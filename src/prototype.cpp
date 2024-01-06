#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

class Shape {
public:
	virtual ~Shape(){}
	virtual Shape* clone() const = 0;
	virtual void draw() const = 0;
};

class Circle : public Shape {
private:
	int m_radius;
public:
	Circle(int radius):m_radius(radius){}
	Shape* clone() const override {
		return new Circle(*this);
	}
	void draw() const override {
		cout << "Drawing Circle with radius:" << m_radius << endl;
	}
};

class Rectangle : public Shape {
private:
	int m_width;
	int m_height;
public:
	Rectangle(int width, int height):m_width(width),m_height(height){}
	Shape* clone() const override {
		return new Rectangle(*this);
	}
	void draw() const override {
		cout << "Drawing Rectangle width" << m_width << "and height" << m_height << endl;
	}
};

class ShapePrototypeManager {
private:
	unordered_map<string, Shape*> m_prototypes;
public:
	Shape* getShapePrototype(const string &type) {
		auto it = m_prototypes.find(type);
		if (it != m_prototypes.end()) {
			return it->second->clone();
		}
		return nullptr;
	}
	void addPrototype(const string &type, Shape* prototype) {
		m_prototypes[type] = prototype;
	}
};

int main() {
	ShapePrototypeManager prototypemanager;
	Circle circlePrototype(5);
	Rectangle rectanglePrototype(4,6);

	prototypemanager.addPrototype("Circle", &circlePrototype);
	prototypemanager.addPrototype("Rectangle", &rectanglePrototype);
	Shape* shape1 = prototypemanager.getShapePrototype("Circle");
	Shape* shape2 = prototypemanager.getShapePrototype("Rectangle");

	if (shape1 && shape2) {
		shape1->draw();
		shape2->draw();

		delete shape1;
		delete shape2;
	}
	return 0;
}
