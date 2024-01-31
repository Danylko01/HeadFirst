#include<iostream>
using namespace std;

// 被适配对象基类
class DrawingAPI {
public:
	virtual void drawCircle() = 0;
	virtual void drawSquare() = 0;
};

// 被适配对象
class WindowsAPI : public DrawingAPI {
public:
	void drawCircle() override {
		cout << "Drawing a circle on windows." << endl;		
	}
	void drawSquare() override {
		cout << "Drawing a square on windows." << endl;
	}
};

class LinuxAPI : public DrawingAPI {
public:
	void drawCircle() override {
		cout << "Drawing a cirlce on Linux." << endl;
	}
	void drawSquare() override {
		cout << "Drawing a square on Linux." << endl;
	}
};
// 目标接口
class Shape {
protected:
	DrawingAPI* drawingAPI;
public:
	Shape(DrawingAPI* api) : drawingAPI(api) {}
	virtual void draw() = 0;
};

// 适配器
class Circle : public Shape {
public:
	Circle(DrawingAPI* api): Shape(api) {}
	void draw() override {
		cout << "Drawing Circle." << endl;
		drawingAPI->drawCircle();
	}
};

// 适配器
class Square : public Shape {
public:
	Square(DrawingAPI* api): Shape(api) {}
	void draw() override {
		cout << "Drawing Square." << endl;
		drawingAPI->drawSquare();
	}
};

int main() {
	DrawingAPI* winApi = new WindowsAPI();
	DrawingAPI* linApi = new LinuxAPI();
	Shape* circle = new Circle(winApi);
	Shape* square = new Square(linApi);
	
	circle->draw();
	square->draw();
	delete winApi;
	delete linApi;
	delete circle;
	delete square;
	return 0;
}
