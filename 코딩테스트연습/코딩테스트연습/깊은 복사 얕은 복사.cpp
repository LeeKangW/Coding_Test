#include<iostream>
#include<string>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

using namespace std;

class Test
{
public:
	char* name;
	int age;

public:
	explicit Test() = default;
	explicit Test(const char* p_name, int p_age)
	{
		age = p_age;
		name = new char[strlen(p_name) + 1];
		strcpy(name, p_name);
	}
	Test(const Test& rhs);

	Test operator=(const Test& rhs)
	{
		age = rhs.age;
		name = new char[strlen(rhs.name) + 1];
		strcpy(name, rhs.name);

		return *this;
	}
	void show() const { cout << name << ", " << age << endl; }
};

Test::Test(const Test& rhs)
{
	age = rhs.age;
	name = new char[strlen(rhs.name + 1) + 1];
	strcpy(name, rhs.name);
}
int main()
{
	Test t("Lee", 3);
	Test t2;
	t2 = t;
	strcpy(t.name, "Park");

	t.show();
	t2.show();

}