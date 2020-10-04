#include "car.h"
#include <iostream>

car::car()
{
	std::cout << "car()" << std::endl;
	fuel = 0;
	speed = 0;
	passengers = 0;
}

car::car(float amount)
{
	fuel = amount;
	speed = 0;
	passengers = 0;
}

car::~car()
{
	std::cout << "~car()" << std::endl;
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
}
