/*
 * Sensor.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */

#include "Sensor.h"

Sensor::Sensor(int id) {
	this->sensorData.id = id;
	this->sensorData.data = 0;
	this->listener = NULL;
}

void Sensor::setVal(int8_t val) {
	if (this->sensorData.data != val) {
		this->sensorData.data = val;
		if (listener != NULL) {
			listener->notify(sensorData);
		}
	}
}

SensorData Sensor::getSensorData() {
	return this->sensorData;
}

void Sensor::addListener(SensorListener *listener) {
	this->listener = listener;
}
Sensor::~Sensor() {
}

