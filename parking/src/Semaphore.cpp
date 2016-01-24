/*
 * Semaphore.cpp
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */

#include "Semaphore.h"
#include <iostream>

using namespace std;

Semaphore::Semaphore() :
		color(GREEN) {

}
void Semaphore::setColor(int color) {
	if (this->color != color) {
		this->color = color;
		switch (color) {
		case RED:
			cout << "Semaphore is  RED" << endl;
			break;
		case GREEN:
			cout << "Semaphore is GREEN" << endl;
			break;
		default:
			break;
		}

	}
}

Semaphore::~Semaphore() {
}

