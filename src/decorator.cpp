#include<iostream>
#include<string>
// 装饰者模式，主要用于功能拓展
using namespace std;
// 抽象组件
class Coffee {
	public:
		virtual ~Coffee(){}
		virtual double getCost() = 0;
		virtual string getDescription() = 0;
};
// 具体组件
class SimpleCoffee : public Coffee {
	public:
		double getCost() override {
			return 5.0;
		}

		string getDescription() override {
			return "Simple Coffee";
		}
};
// 抽象装饰者
class CoffeeDecorator : public Coffee {
	protected:
		Coffee* m_coffee;
	public:
		CoffeeDecorator(Coffee* coffee) : m_coffee(coffee){}
		double getCost() override {
			return m_coffee->getCost();
		}
		string getDescription() override {
			return m_coffee->getDescription();
		}
};

// 具体装饰者 -奶泡
class FoamDecorator : public CoffeeDecorator {
	public:
		FoamDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}
		double getCost() override {
			return m_coffee->getCost() + 2.0;
		}
		string getDescription() override {
			return m_coffee->getDescription() + ", Foam";
		}
};

class ChocolateDecorator : public CoffeeDecorator {
	public:
	ChocolateDecorator(Coffee* coffee) : CoffeeDecorator(coffee) {}
	double getCost() override {
		return m_coffee->getCost() + 3.0;
	}
	string getDescription() override {
		return m_coffee->getDescription() + ", Chocolate";
	}
};

int main() {
	Coffee* simpleCoffee = new SimpleCoffee();
	cout << "cost: $" << simpleCoffee->getCost() << ",des:" << simpleCoffee->getDescription() << endl;
	Coffee* foamDecorator = new FoamDecorator(simpleCoffee);
	cout << "cost: $" << foamDecorator->getCost() <<", des:" << foamDecorator->getDescription() << endl;
	Coffee* chocolate = new ChocolateDecorator(simpleCoffee);
	cout << "cost: $" << chocolate->getCost() << ",des:" << chocolate->getDescription() << endl;
	delete simpleCoffee;
	delete foamDecorator;	
}
