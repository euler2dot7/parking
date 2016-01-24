/*
 * SensorListener.hpp
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */

#ifndef SENSORLISTENER_HPP_
#define SENSORLISTENER_HPP_

struct SensorData {
	int8_t id;
	int8_t data;
};

class SensorListener {
public:
	virtual void notify(SensorData data) = 0;
	virtual ~SensorListener() {
	}
};

#endif /* SENSORLISTENER_HPP_ */
