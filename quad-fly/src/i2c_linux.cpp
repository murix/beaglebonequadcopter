/*
 * bbb_i2c.cpp
 *
 *  Created on: 10/08/2014
 *      Author: root
 */

//printf
#include <stdio.h>

//system
#include <stdlib.h>

//open
#include <unistd.h>
#include <fcntl.h>

#include "i2c_linux.h"

void i2c_linux::open(){



	if ((this->fd = ::open("/dev/i2c-1",O_RDWR|O_LARGEFILE)) < 0) {
		printf("Failed to open the bus.");
		exit(1);
	}

}


