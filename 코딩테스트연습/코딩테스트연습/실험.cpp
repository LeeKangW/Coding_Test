#include<iostream>
using namespace std;

template<class T>
void show(T t) {
	t++;
	cout << t << endl;
}
template<>
void show(string t) {
	cout << "++이 없음." << endl;
	cout << t << endl;
}

int main() {
	int a = 2;
	double s = 3;
	string str = "스트링";

	show<int>(a);
	show<double>(s);
	show<string>(str);

}