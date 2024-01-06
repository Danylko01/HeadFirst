#include<iostream>
#include<string>
using namespace std;

class Computer {
private:
	string m_processor;
	string m_memory;
	string m_storage;
public:
	void setProcessor(string processor) {
		m_processor = processor;
	}
	void setMemory(string memory) {
		m_memory = memory;
	}
	void setStorage(string storage) {
		m_storage = storage;
	}
	void showInfo() const {
		cout << "Computer Configuration:\n"
			<< "Processor: " << m_processor << "\n"
			<< "Memory: " << m_memory << "\n"
			<< "Storage: " << m_storage << "\n\n";
	}
};

class ComputerBuild {
public:
	virtual void buildProcessor() = 0;
	virtual void buildMemory() = 0;
	virtual void buildStorage() = 0;
	virtual Computer getResult() const = 0;
};

class HighEndComputerBuilder:public ComputerBuild {
private:
	Computer m_computer;
public:
	void buildProcessor() override {
		m_computer.setProcessor("Intel i9");
	}
	void buildMemory() override {
		m_computer.setMemory("32G DDR4");
	}
	void buildStorage() override {
		m_computer.setStorage("1TB NVMe SSD");
	}
	Computer getResult() const override {
		return m_computer;
	}
}; 

class LowEndComputerBuilder:public ComputerBuild {
private:
	Computer m_computer;
public:
	void buildProcessor() override {
		m_computer.setProcessor("Intel i3");
	}
	void buildMemory() override {
		m_computer.setMemory("8GB DDR4");
	}
	void buildStorage() override {
		m_computer.setStorage("256GB SSD");
	}
	Computer getResult() const override {
		return m_computer;
	}
};

class ComputerDirector {
public:
	Computer buildComputer(ComputerBuild& builder) {
		builder.buildProcessor();
		builder.buildMemory();
		builder.buildStorage();
		return builder.getResult();
	} 
};

int main() {
	// 创建导演和生成器
	ComputerDirector director;
	HighEndComputerBuilder highEndBuilder;
	LowEndComputerBuilder lowEndBuilder;

	Computer hightEndComputer = director.buildComputer(highEndBuilder);
	hightEndComputer.showInfo();

	Computer lowEndComputer = director.buildComputer(lowEndBuilder);
	lowEndComputer.showInfo();
	return 0;
}
