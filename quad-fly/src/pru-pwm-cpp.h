/* Copyright (c) 2013 Owen McAree
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
 
 #ifndef pruPWM_h
 #define pruPWM_h
 
 #include <limits.h>
 #include "pru.h"
 
 
 class PRUPWM : private PRU {
 public:
	PRUPWM(unsigned int frequency = 400);
	void start();
	using PRU::stop;
	
	void setFrequency(unsigned int frequency);
	void setChannelValue(unsigned int channel, unsigned long pwm_ns);	
	void setFailsafeValue(unsigned int channel, unsigned long pwm_ns);
	void setFailsafeTimeout(unsigned int timeout_ms);
 private:
	void setPRUDuty(unsigned int channel, unsigned long pwm_ns);
	void updateFailsafe();
	static const unsigned int nanosecondsPerCycle = 95;
	unsigned int pwmFrequency;
	unsigned int failsafeTimeout;
};
 
 #endif
