#include<iostream>

using namespace std;

class Dog {
	int num;
public:
	Dog(int num) :num{ num } { cout << num << "持失切"<<endl; }
	~Dog() {
		cout << num << "社瑚切" << endl;
	}
};

int main() {
	Dog dog(1);
	Dog dog2(2);
	Dog dog3(3);
	Dog dog4(4);
	Dog dog5(5);
	Dog dog6(6);
}
