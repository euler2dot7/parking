/*
 * Sensor.h
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */

#ifndef SENSOR_H_
#define SENSOR_H_
#include <iostream>
#include "SensorListener.hpp"
class Sensor {
public:
	Sensor(int id);
	void setVal(int8_t val);
	SensorData getSensorData();
	void addListener(SensorListener *listener);
	virtual ~Sensor();
private:
	SensorListener* listener;
	SensorData sensorData;
};

#endif /* SENSOR_H_ */
