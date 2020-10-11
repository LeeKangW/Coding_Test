#include<iostream>
#include<fstream>
#include<vector>
#include<string>

//#define withSpace
using namespace std;

class Test
{
private:
	string Name = "";
	int age = 0;

public:
	Test() = default;
	Test(string name, int p_age) :Name(name), age(p_age){}

	void SetName(string name) { Name = name; }
	void SetAge(int age) { this->age = age; }
	
	string GetName() const
	{
		return Name;
	}
	int GetAge() const { return age; }


	void show() const
	{
		cout << "�̸� : " << Name << ", ���� : " << age << endl;
	}
};
int main()
{	
	// Ÿ ��ο� ���� �� \ �� �ι��� �ʿ��ϴ�.
	// �Ϲ� �ڷ��� �����
	/*
	ifstream in("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\�ڵ��׽�Ʈ����\\��������¿���\\��������.txt");
	ofstream out("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\�ڵ��׽�Ʈ����\\��������¿���\\�������.txt");
	*/

	// class �Ǵ� struct �ڷ��� �����
	ifstream in("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\�ڵ��׽�Ʈ����\\��������¿���\\Ŭ�����Է�����.txt");
	ofstream out("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\�ڵ��׽�Ʈ����\\��������¿���\\Ŭ�����������.txt");

	bool withclass = true;
	if (in.is_open())
	{
		cout << "������ ����" << endl;
#ifdef withSpace

		if (withclass)
		{
			vector<Test> v;

			Test t;
		}
		else
		{
			/**
			 * ���� ���� -> ���� �� char�� �޾ƾ� ��.
			 */
			char n;
			while ((n = in.get()) != EOF)
			{
				out << n;
			}
		}
		
#else
		if (withclass)
		{
			vector<Test> v;

			Test t;
			string str;
			while (!in.eof())
			{
				in >> str;
				t.SetName(str);
				in >> str;
				t.SetAge(stoi(str));
				v.push_back(t);
			}

			for (const Test& t : v)
			{
				t.show();
				out <<"�̸� : "<< t.GetName()<<" ";
				out <<"���� : "<< t.GetAge()<<endl;
			}
		}
		else
		{
			/**
			 * ���� ����.
			 */
			string c;
			while (in >> c)
			{
				out << c;
			}
		}
		
#endif
	}
	else
	{
		cout << "������ �������� ����." << endl;
	}
	in.close();
	out.close();
}