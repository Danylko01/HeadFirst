#include<iostream>
#include<mutex>

using namespace std;

class Singleton {
private:
	// 私有构造函数防止外部直接实例化
	Singleton(){}
	static Singleton* m_instance;
	static mutex m_mutex;
public:
	static Singleton* getInstance(){
		// 双检查锁
		if (!m_instance) {
			lock_guard<mutex> lock(m_mutex);
			if (!m_instance) {
				m_instance = new Singleton();
			}
		}
		return m_instance;
	}
};

Singleton* Singleton::m_instance = nullptr;
mutex Singleton::m_mutex;

int main() {
	Singleton* instance1 = Singleton::getInstance();
	Singleton* instance2 = Singleton::getInstance();
	if (instance1 == instance2) {
		cout << "Two instances are the same." << endl;
	}
	else {
		cout << "Two instances are different." << endl;
	}
	return 0;
}
