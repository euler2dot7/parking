/*
 * GatesController.hpp
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */

#ifndef GATESLISTENER_HPP_
#define GATESLISTENER_HPP_

class GateListener {
public:
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	virtual ~GateListener() {
	}
};

#endif /* GATESLISTENER_HPP_ */
