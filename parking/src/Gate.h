/*
 * Gate.h
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */

#ifndef GATE_H_
#define GATE_H_
#include <iostream>
#include <mutex>

#include "GatesListener.hpp"
#include "Sensor.h"
#include "SensorListener.hpp"

enum GateStates {
	ZERO, ENTER_1, ENTER_2, ENTER_3, EXIT_1, EXIT_2, EXIT_3, ERROR
};

class Gate: public SensorListener {
public:
	Gate(Sensor *, Sensor *);
	void notify(SensorData data);
	void setGatesController(GateListener *);
	virtual ~Gate();
private:
	const int8_t internalSensorId;
	const int8_t externalSensorId;
	Sensor *sensors[2];
	GateStates currentState;
	GateListener * gateController;
	std::mutex mtx;
};

#endif /* GATE_H_ */
