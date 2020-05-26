#include<iostream>
#include<algorithm>
#include<vector>
#include<array>

using namespace std;

class Dog {
	int num;
public:
	Dog() = default;
	Dog(int num) :num{ num } { cout << num << "持失切"<<endl; }
	~Dog() {
		cout << num << "社瑚切" << endl;
	}
	void show() {};
};

int main() {

	array<int,10>arr{ 2,5,1,3,7,56,4,6,8,89 };
	vector<int> v{ 1,2,6,6,4,6,88,3,1234,124,56,77 };
	
	sort(v.begin(), v.end());
	
	for(vector<int>::)
	/*Dog dog(1);
	Dog dog2(2);
	Dog dog3(3);
	Dog dog4(4);
	Dog dog5(5);
	Dog dog6(6);*/
}
