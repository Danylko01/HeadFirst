// 工厂方法，把类的实例化延迟到子类
#include<iostream>
using namespace std;

class Shape {
public:
	virtual ~Shape(){}
	virtual void draw() = 0;
};

class CirCle : public Shape {
public:
	void draw() override {
		cout << "Drawing a circle." << endl;
	}
};

class Rectangle : public Shape {
public:
	void draw() override {
		cout << "Drawing a rectangle." << endl;
	}
};

class ShapeFactory {
public:
	virtual ~ShapeFactory(){}
	virtual Shape* createShape() = 0;
};

class CirCleFactory : public ShapeFactory {
public:
	Shape* createShape() override {
		return new CirCle();
	}
};

class RectangleFactory : public ShapeFactory {
public:
	Shape* createShape() override {
		return new Rectangle();
	}
};

int main() {
	ShapeFactory* circleFactory = new CirCleFactory();
	Shape* circle = circleFactory->createShape();
	circle->draw();

	ShapeFactory* rectangleFactory = new RectangleFactory();
	Shape* rectangle = rectangleFactory->createShape();
	rectangle->draw();

	delete circle;
	delete circleFactory;
	delete rectangle;
	delete rectangleFactory;
	return 0;
}
