#pragma once
class car {
private:
	float fuel;
	float speed;
	int passengers;
	static int totalCount;
public:
	car();
	car(float amount);
	car(float amount, int pass);
	~car();
	void fillFuel(float amount); //if the function is defined in the class directly, the function is automatically inline
	void accelerate();
	void brake();
	void addPassengers(int count);
	void dashboard();
	static void showCounts();
};