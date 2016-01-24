/*
 * SerialCommunicator.cpp
 *
 *  Created on: Jan 24, 2016
 *      Author: x
 */
#include <stdio.h>
#include "SerialCommunicator.h"

SerialCommunicator::SerialCommunicator() :
		STX(0x01), ETX(0x02) {

}

void SerialCommunicator::sendNumberOfVehicles(uint32_t n) {
	unsigned char bytes[6];

	bytes[0] = STX;
	bytes[1] = (n >> 24) & 0xFF;
	bytes[2] = (n >> 16) & 0xFF;
	bytes[3] = (n >> 8) & 0xFF;
	bytes[4] = n & 0xFF;
	bytes[5] = ETX;
	printf("serial msg: %x%x%x%x%x%x\n", bytes[0], bytes[1], bytes[2], bytes[3], bytes[4], bytes[5]);
}

SerialCommunicator::~SerialCommunicator() {
}

