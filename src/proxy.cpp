#include<iostream>
#include<string>
using namespace std;

// 抽象主题
class Image {
	public:
		virtual ~Image(){}
		virtual void display() = 0;
};

class RealImage : public Image {
	private:
		string m_filename;
	public:
		RealImage(const string& filename) : m_filename(filename) {
			loadImageFromDisk();
		}
		void display() override {
			cout << "Displaying image:" << m_filename << endl;
		}
	private:
		void loadImageFromDisk() {
			cout << "Loading image from disk:" << m_filename << endl;
		}
};

// 代理
class ProxyImage  : public Image {
	private: 
		RealImage* m_realImage;
		string m_filename;
	public:
		ProxyImage(const string& filename) : m_filename(filename), m_realImage(nullptr){}
		void display() override {
			if (m_realImage == nullptr) {
				m_realImage = new RealImage(m_filename);
			}
			m_realImage->display();
		}
		~ProxyImage() {
			delete m_realImage;
		}
};

int main() {
	Image* image1 = new ProxyImage("image1.jpg");
	Image* image2 = new ProxyImage("image2.png");

	// 图片将在需要时jiazai
	image1->display();
	image1->display();

	image2->display();

	delete image1;
	delete image2;
	return 0;
}
