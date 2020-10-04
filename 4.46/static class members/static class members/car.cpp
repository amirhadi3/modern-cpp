#include "car.h"
#include <iostream>

int car::totalCount = 0;

void car::showCounts() {
	std::cout << "total cars: " << totalCount << std::endl;
}

car::car()
{
	std::cout << "car()" << std::endl;
	fuel = 0;
	speed = 0;
	passengers = 0;
	++totalCount;
}

car::car(float amount)
{
	fuel = amount;
	speed = 0;
	passengers = 0;
	++totalCount;
}

car::~car()
{
	std::cout << "~car()" << std::endl;
	--totalCount;
}

void car::fillFuel(float amount)
{
	fuel = amount;
}

void car::accelerate()
{
	speed++;
	fuel -= 0.5f;
}

void car::brake()
{
	speed = 0;
}

void car::addPassengers(int count)
{
	passengers = count;
}

void car::dashboard()
{
	std::cout << "fuel: " << fuel << std::endl;
	std::cout << "speed: " << speed << std::endl;
	std::cout << "passengers: " << passengers << std::endl;
	std::cout << "total cars: " << totalCount << std::endl;
}
