#pragma once
class car {
private:
	float fuel;
	float speed;
	int passengers;
public:
	car();
	car(float amount);
	~car();
	void fillFuel(float amount); //if the function is defined in the class directly, the function is automatically inline
	void accelerate();
	void brake();
	void addPassengers(int count);
	void dashboard();
};