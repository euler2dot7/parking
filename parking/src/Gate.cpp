/*
 * Gate.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */
#include "Gate.h"

Gate::Gate(Sensor* internal, Sensor* external) :
		internalSensorId(internal->getSensorData().id), externalSensorId(external->getSensorData().id) {
	this->sensors[0] = internal;
	this->sensors[1] = external;
	this->currentState = ZERO;
	this->gateController = NULL;
	internal->addListener(this);
	external->addListener(this);
}

void Gate::notify(SensorData data) {
	mtx.lock();
	bool isExternal = data.id == externalSensorId;

	switch (currentState) {
	case ZERO:
		currentState = isExternal ? ENTER_1 : EXIT_1;
		break;
	case ENTER_1:
		currentState = !isExternal ? ENTER_2 : ZERO;
		break;
	case ENTER_2:
		currentState = isExternal ? ENTER_3 : ENTER_1;
		break;
	case ENTER_3:
		currentState = !isExternal ? ZERO : ENTER_2;
		if (currentState == ZERO && gateController != NULL) {
			gateController->onEnter();
		}
		break;
	case EXIT_1:
		currentState = isExternal ? EXIT_2 : ZERO;
		break;
	case EXIT_2:
		currentState = !isExternal ? EXIT_3 : EXIT_1;
		break;
	case EXIT_3:
		currentState = isExternal ? ZERO : EXIT_2;
		if (currentState == ZERO && gateController != NULL) {
			gateController->onExit();
		}
		break;
	default:
		break;
	}
	mtx.unlock();
}

void Gate::setGatesController(GateListener * gateController) {
	this->gateController = gateController;
}

Gate::~Gate() {
}

