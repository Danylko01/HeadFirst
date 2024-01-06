#include<iostream>
using namespace std;

class Car {
public:
	virtual ~Car(){}
	virtual void drive() = 0;
};

class LuxuryCar : public Car {
public:
	void drive() override {
		cout << "driving a luxury car." << endl;
	}
};

class RegularCar : public Car {
public:
	void drive() override {
		cout << "driving a regular car." << endl;
	}
};

class Engine {
public:
	virtual ~Engine(){}
	virtual void start() = 0;
};

class HighPerformanceEngine : public Engine {
public:
	void start() override {
		cout << "starting a high-performance engine." << endl;
	}
};

class RegularEngine : public Engine {
public:
	void start() override {
		cout << "start a regular engine." << endl;
	}
};

class AbstractFactory {
public:
	virtual ~AbstractFactory(){}
	virtual Car* createCar() = 0;
	virtual Engine* createEngine() = 0;
};

class LuxuryFactory : public AbstractFactory {
public:
	Car* createCar() override {
		return new LuxuryCar();
	}
	Engine* createEngine() override {
		return new HighPerformanceEngine();
	}
};

class RegularFactory : public AbstractFactory {
public:
	Car* createCar() override {
		return new RegularCar();
	}
	Engine* createEngine() override {
		return new RegularEngine();
	}
};

int main() {
	AbstractFactory* luxuryFactory = new LuxuryFactory();
	Car* luxuryCar = luxuryFactory->createCar();
	Engine* hignPerformanceEngine = luxuryFactory->createEngine();
	luxuryCar->drive();
	hignPerformanceEngine->start();

	AbstractFactory* regularFactory = new RegularFactory();
	Car* regularCar = regularFactory->createCar();
	Engine* regularEngine = regularFactory->createEngine();
	regularCar->drive();
	regularEngine->start();

	delete luxuryFactory;
	delete regularFactory;
	delete luxuryCar;
	delete regularCar;
	delete hignPerformanceEngine;
	delete regularEngine;
	return 0;
}
