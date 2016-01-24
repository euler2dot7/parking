/*
 * Semaphore.h
 *
 *  Created on: Jan 23, 2016
 *      Author: x
 */

#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_
#include <stdint.h>
enum SemaphoreColor {
	RED = 0, GREEN = 1
};
class Semaphore {
public:
	Semaphore();
	void setColor(int color);
	virtual ~Semaphore();
private:
	int8_t color;
};

#endif /* SEMAPHORE_H_ */
