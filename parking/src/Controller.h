/*
 * Controller.h
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include <mutex>
#include <stdint.h>

#include "GatesListener.hpp"
#include "Semaphore.h"
#include "SerialCommunicator.h"

class Controller: public GateListener {
public:
	Controller(Semaphore *semaphore, SerialCommunicator * serial, uint32_t maxVehiclesNum = 10);
	void onEnter();
	void onExit();
	virtual ~Controller();
private:
	uint32_t count;
	Semaphore * semaphore;
	SerialCommunicator * serial;
	uint32_t maxVehiclesNum;
	void setSemaphoreColor(int color);
	void onCount(uint32_t);
	std::mutex mtx;
};

#endif /* CONTROLLER_H_ */
