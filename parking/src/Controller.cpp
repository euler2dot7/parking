/*
 * Controller.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */

#include <iostream>

#include "Controller.h"

using namespace std;
Controller::Controller(Semaphore * semaphore, SerialCommunicator * serial, uint32_t maxVehiclesNum) :
		count(0), semaphore(semaphore), serial(serial), maxVehiclesNum(maxVehiclesNum) {
	this->semaphore->setColor(GREEN);
}

void Controller::onEnter() {
	mtx.lock();
	count++;
	onCount(count);
	mtx.unlock();
}

void Controller::onExit() {
	mtx.lock();
	count = count == 0 ? 0 : count - 1;
	onCount(count);
	mtx.unlock();
}
void Controller::setSemaphoreColor(int color) {
	if (semaphore != NULL) {
		semaphore->setColor(color);
	}
}

void Controller::onCount(uint32_t count) {
	serial->sendNumberOfVehicles(count);
	if (count == maxVehiclesNum) {
		setSemaphoreColor(RED);
	}
	if (count == maxVehiclesNum - 1) {
		setSemaphoreColor(GREEN);
	}
}

Controller::~Controller() {

}

