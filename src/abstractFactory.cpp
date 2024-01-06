#include<iostream>
using namespace std;

class Chair {
public:
	virtual ~Chair(){}
	virtual void sitOn() const = 0;
};

class ModernChair:public Chair{
public:
	void sitOn() const override {
		cout << "现代风格椅子\n";
	}
};

class OrientChair:public Chair {
public:
	void sitOn() const override {
		cout << "古风椅子\n";
	}
};

class Table {
public:
	virtual ~Table(){}
	virtual void putOn() const = 0;
};

class ModernTable : public Table {
public:
	void putOn() const override {
		cout << "现代风格桌子\n";
	}
};

class OrientTable : public Table {
public:
	void putOn() const override {
		cout << "古风桌子\n";
	}
};

class FurnitureFacory { //抽象工厂
public:
	virtual ~FurnitureFacory(){}
	virtual Chair* createChair() const = 0;
	virtual Table* createTable() const = 0;
};
class ModernFactory:public FurnitureFacory {
public:
	Chair* createChair() const override {
		return new ModernChair();
	}
	Table* createTable() const override {
		return new ModernTable();
	}
};
class OrientFactory:public FurnitureFacory {
public:
	Chair* createChair() const override {
		return new OrientChair();
	}
	Table* createTable() const override {
		return new OrientTable();
	}
};
class Client {
private:
	FurnitureFacory* m_factory;
public:
	Client(FurnitureFacory* factory) {
		setFactory(factory);
	}
	void buyFurniture() {
		Chair* chair = m_factory->createChair();
		Table* table = m_factory->createTable();
		chair->sitOn();
		table->putOn();
		delete chair;
		delete table;
	}
	void setFactory(FurnitureFacory *factory) {
		m_factory = factory;
	}
};
int main() {
	ModernFactory modernFactory;
	Client client(&modernFactory);
	client.buyFurniture();
	OrientFactory orientFactory;
	client.setFactory(&orientFactory);
	client.buyFurniture();
	return 0;
}
