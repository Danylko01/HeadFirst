#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Subject;

// 观察者接口
class Observer {
	public:
		virtual void update(const Subject& subject) = 0;
};

// 主题接口
class Subject {
	private:
		vector<Observer*> observers;
		int state;
	public:
		// 添加观察者对象
		virtual void attach(Observer* observer) {
			observers.push_back(observer);
		}
		// 删除观察者对象
		virtual void detach(Observer* observer) {
			auto it = find(observers.begin(), observers.end(), observer);
			if (it != observers.end()) {
				observers.erase(it);
			}
		}
		// 向观察者发送通知
		virtual void notify() {
			for (auto observer : observers) {
				observer->update(*this);
			}
		}
		virtual int getState() const {
			return state;
		}
		virtual void setState(int newState) {
			state = newState;
			notify();
		}
};

// 观察者对象A
class ObserverA : public Observer {
	public:
		void update(const Subject& subject) override {
			cout << "ObserverA: Subject state has changed to " << subject.getState() << endl;
		}
};

class ObserverB : public Observer {
	public:
		void update(const Subject& subject) override {
			cout << "ObserverB: subject state has changed to " << subject.getState() << endl; 
		}
};

int main() {
	Subject subject;
	ObserverA observerA;
	ObserverB observerB;
	subject.attach(&observerA);
	subject.attach(&observerB);
	subject.setState(10);
	subject.detach(&observerB);
	subject.setState(20);
	return 0;
}
