#include <iostream>
#include <string>
using namespace std;

// 抽象产品类
class Product {
	public:
		virtual ~Product(){}
		virtual void display() const = 0;
		void productMethod() {
			cout << "parent method" << endl;
		}
};
// 具体产品类A
class ConcreteProductA : public Product {
	private:
		string propertyA;
	public:
		ConcreteProductA(const string& propA) : propertyA(propA){}
		void display() const override {
			cout << "ConcreteProductA with property:" << propertyA << endl;
		}
		void additionMethodA() const {
			cout << "Additional method specific to ConcreteProductA" << endl;
		}
};
// 具体产品类B
class ConcreteProductB : public Product {
	private:
		int propertyB;
	public:
		ConcreteProductB(int propB) : propertyB(propB) {}
		void display() const override {
			cout << "ConcreteProductB with property:" << propertyB << endl;
		}
		void additionMethodB() const {
			cout << "Additional method specific to ConcreteProductB" << endl;
		}
};
// 抽象工厂类
class Factory {
	public:
		virtual ~Factory(){}
		virtual Product* createProduct() const = 0;
};
// 具体工厂类A
class ConcreteFactoryA : public Factory {
	public:
		Product* createProduct() const override {
			return new ConcreteProductA("propertyA_value");
		}
};
// 具体工厂类B
class ConcreteFactoryB : public Factory {
	public:
		Product* createProduct() const override {
			return new ConcreteProductB(24);
		}
};
int main() {
	// 使用具体工厂A创建产品A
	Factory* factoryA = new ConcreteFactoryA();
	Product* productA = factoryA->createProduct();
	productA->display();
	productA->productMethod();
	// 调用特有方法和属性
	ConcreteProductA* concreteProductA = dynamic_cast<ConcreteProductA*>(productA);
	if (concreteProductA) {
		concreteProductA->additionMethodA();
	}
	// 使用具体工厂B创建产品B
	Factory* factoryB = new ConcreteFactoryB();
	Product* productB = factoryB->createProduct();
	productB->display();
	// 调用特有的方法和属性
	ConcreteProductB* concreteProductB = dynamic_cast<ConcreteProductB*>(productB);
	if (concreteProductB) {
		concreteProductB->additionMethodB();
	}
	// 释放资源
	delete factoryA;
	delete productA;
	delete factoryB;
	delete productB;
	return 0;
}
