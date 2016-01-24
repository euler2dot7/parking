/*
 * SerialCommunicator.h
 *
 *  Created on: Jan 24, 2016
 *      Author: x
 */

#ifndef SERIALCOMMUNICATOR_H_
#define SERIALCOMMUNICATOR_H_
#include <stdint.h>
class SerialCommunicator {
public:
	SerialCommunicator();
	void sendNumberOfVehicles(uint32_t);
	virtual ~SerialCommunicator();
private:
	const unsigned char STX;
	const unsigned char ETX;
};

#endif /* SERIALCOMMUNICATOR_H_ */
