#ifndef CONCRETE_STRATEGY_H
#define CONCRETE_STRATEGY_H

#include "strategy.h"
#include <iostream>

// 自行车
class Bike : public ITransport
{
public:
	void Run() override { 
		std::cout << "By bike" << std::endl;
	}
};

// 汽车
class Car : public ITransport
{
public:
	void Run() override { 
		std::cout << "By car" << std::endl;
	}
};

// 火车
class Train : public ITransport
{
public:
	void Run() override {
		std::cout << "By train" << std::endl;
	}
};

#endif // CONCRETE_STRATEGY_H
