#include <iostream>
#include "Sensor.h"
#include "Controller.h"
#include "Gate.h"
#include "GatesListener.hpp"

#define S1_ID 1
#define S2_ID 2
#define S3_ID 3
#define S4_ID 4

using namespace std;

void enterSimulation(Sensor * internal, Sensor * external);
void exitSimulation(Sensor * internal, Sensor * external);

int main() {
	puts("Start");
	// Creazione di 4 sensori virtuali, 2 per ogni gate
	Sensor *sensor1 = new Sensor(S1_ID);
	Sensor *sensor2 = new Sensor(S2_ID);
	Sensor *sensor3 = new Sensor(S3_ID);
	Sensor *sensor4 = new Sensor(S4_ID);

	// Creazione di due gate
	Gate gateOne(sensor1, sensor2);
	Gate gateTwo(sensor3, sensor4);

	Semaphore * mockSemaphore = new Semaphore();
	SerialCommunicator * mockSerial = new SerialCommunicator();

	//Creazione del controller
	GateListener * controller = new Controller(mockSemaphore, mockSerial);

	// Controller inizia ad ascoltare gli eventi provenienti da entrambi i gate;
	gateOne.setGatesController(controller);
	gateTwo.setGatesController(controller);

	// Simulazione di 10 entrate attraverso gateOne
	for (int var = 0; var < 10; ++var) {
		enterSimulation(sensor1, sensor2);
	}
	//Simulazione di 10 uscite attraverso gateTwo
	for (int var = 0; var < 10; ++var) {
		exitSimulation(sensor3, sensor4);
	}
	return 0;
}

void enterSimulation(Sensor * internal, Sensor * external) {
	external->setVal(1);
	internal->setVal(1);
	external->setVal(0);
	internal->setVal(0);
}

void exitSimulation(Sensor * internal, Sensor * external) {
	enterSimulation(external, internal);
}
