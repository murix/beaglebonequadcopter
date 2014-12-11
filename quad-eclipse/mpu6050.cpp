/*
 * mpu6050.cpp
 *
 *  Created on: 10/08/2014
 *      Author: root
 */

//i2c defines
#include "i2c-dev.h"
//ioctl
#include <sys/ioctl.h>
//swap
#include <endian.h>
//printf,perror
#include <stdio.h>
// int types
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
//sqrt
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


#include "mpu6050.h"
#include "timestamps.h"

mpu6050::mpu6050(int fd){
	this->fd=fd;
	this->tc=0;

	this->gyro_off[0]=0;
	this->gyro_off[1]=0;
	this->gyro_off[2]=0;

	//
	init();
	//pre calibration
	gyro_calibration(10);

	gyro_integrate_reset();
	this->t_back=get_timestamp_in_seconds();
	this->t_now=get_timestamp_in_seconds();
	this->t_diff=0;

	this->fusion_pitch=0;
	this->fusion_roll=0;
}

void mpu6050::gyro_integrate_reset(){
	//
	this->gyro_integrate[0]=0;
	this->gyro_integrate[1]=0;
	this->gyro_integrate[2]=0;
}

void mpu6050::gyro_calibration(int samples){
	//zero sum
	this->gyro_off[0]=0;
	this->gyro_off[1]=0;
	this->gyro_off[2]=0;
	//sum
	for(int i=0;i<samples;i++){
		update();
		this->gyro_off[0]+=gyro_raw[0];
		this->gyro_off[1]+=gyro_raw[1];
		this->gyro_off[2]+=gyro_raw[2];
	}
	//avg
	this->gyro_off[0] /= (float) samples;
	this->gyro_off[1] /= (float) samples;
	this->gyro_off[2] /= (float) samples;

	//
	gyro_integrate_reset();
}

void mpu6050::init(){
	//
	if(ioctl(fd,I2C_SLAVE,0x68)<0){
		perror("i2c slave mpu6050 Failed");
		exit(1);
	}
	//master enable
	i2c_smbus_write_byte_data(fd,0x6a,0x00);
	//i2c bypass
	i2c_smbus_write_byte_data(fd,0x37,0x02);
	//wake up from sleep
	i2c_smbus_write_byte_data(fd,0x6b,0x00);
}

void mpu6050::update(){
	//
	t_back=t_now;
	t_now=get_timestamp_in_seconds();
	t_diff=t_now-t_back;
	//printf("%f\r\n",t_diff);

	//
	if(ioctl(fd,I2C_SLAVE,0x68)<0){
		perror("i2c slave mpu6050 Failed");
	}
	//read all
	uint16_t vu[7];
	int16_t vs[7];
	i2c_smbus_read_i2c_block_data(fd,0x3b,14,(uint8_t*)vu);
	for(int i=0;i<7;i++){
		vs[i]=(int16_t) __bswap_16(vu[i]);
	}
	//
	acc[0] =vs[0]/16384.0;
	acc[1] =vs[1]/16384.0;
	acc[2] =vs[2]/16384.0;
	tc     =vs[3]/340.0 + 36.53;
	gyro_raw[0]=(vs[4]/131.0);
	gyro_raw[1]=(vs[5]/131.0);
	gyro_raw[2]=(vs[6]/131.0);
	gyro[0]=gyro_raw[0]-gyro_off[0];
	gyro[1]=gyro_raw[1]-gyro_off[1];
	gyro[2]=gyro_raw[2]-gyro_off[2];

	//radian = speed * time
	gyro_step[0]=-to_radian(gyro[0])*t_diff;
	gyro_step[1]=to_radian(gyro[1])*t_diff;
	gyro_step[2]=to_radian(gyro[2])*t_diff;
	//radian
	gyro_integrate[0] += gyro_step[0];
	gyro_integrate[1] += gyro_step[1];
	gyro_integrate[2] += gyro_step[2];


	//accelerometer
	accn=sqrt(pow(acc[0],2)+pow(acc[1],2)+pow(acc[2],2));


	//
	acc_pitch=atan2(-acc[1],sqrt(pow(acc[0],2)+pow(acc[2],2)));
	acc_roll =atan2(-acc[0],sqrt(pow(acc[1],2)+pow(acc[2],2)));

	//
	double alpha=0.98;
	if(acc[2]<0) alpha=1;
	fusion_pitch = alpha*(fusion_pitch + gyro_step[0] ) + (1-alpha)*acc_pitch;
	fusion_roll  = alpha*(fusion_roll  + gyro_step[1] ) + (1-alpha)*acc_roll;


}

double mpu6050::to_degrees(double radians){
	return radians*(180.0/M_PI);
}
double mpu6050::to_radian(double degree){
	return degree * M_PI/180;
}

