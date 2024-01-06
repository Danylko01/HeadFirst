#include<iostream>

using namespace std;

class Transport {
	public:
		virtual ~Transport(){}
		virtual void deliver() const = 0;
};
class Truck:public Transport {
	public:
		void deliver() const override{
			cout << "卡车运输货物中ing\n";
		}
};

class Ship:public Transport{
	public: 
		void deliver() const override{
			cout << "轮船运输货物中ing \n";
		}
};
class Logistics {
	public:
		virtual ~Logistics(){}
		virtual Transport* factoryMethod() const = 0;
		void doSomething() {
			Transport* transport = factoryMethod();
			transport->deliver();
			delete transport;
		}
};
class TruckLogistics: public Logistics {
	public:
		Transport* factoryMethod() const override {
			return new Truck();
		}
};
class ShipLogistics: public Logistics {
	public:
		Transport* factoryMethod() const override {
			return new Ship();
		}
};
int main() {
	Logistics* truckLogistics = new TruckLogistics();
	Logistics* shipLogistics = new ShipLogistics();
	truckLogistics->doSomething();
	truckLogistics->doSomething();
	shipLogistics->doSomething();
	shipLogistics->doSomething();
	delete truckLogistics;
	delete shipLogistics;
	return 0;
}
