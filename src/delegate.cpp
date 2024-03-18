#include<iostream>

using namespace std;

// 抽象任务接口
class Task {
	public:
		virtual ~Task() {}
		virtual void execute() = 0;
};

// 具体人物类
class ConcreteTaskA : public Task {
	public:
		void execute() override {
			cout << "Exexute Task A" << endl;
		}
};

class ConcreteTaskB : public Task {
	public:
		void execute() override {
			cout << "execute Task B" << endl;
		}
};

// 委派
class TaskDelegator {
	private:
		Task* task;
	public:
		TaskDelegator(Task* t) : task(t) {}
		void delegateTask() {
			task->execute();
		}
};

int main() {
	Task* taskA = new ConcreteTaskA();
	Task* taskB = new ConcreteTaskB();
	TaskDelegator delegateorA(taskA);
	TaskDelegator delegateorB(taskB);

	delegateorA.delegateTask();
	delegateorB.delegateTask();

	delete taskA;
	delete taskB;

	return 0;
}
