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
		cout << "이름 : " << Name << ", 나이 : " << age << endl;
	}
};
int main()
{	
	// 타 경로에 있을 때 \ 는 두번이 필요하다.
	// 일반 자료형 입출력
	/*
	ifstream in("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\코딩테스트연습\\파일입출력연습\\예시파일.txt");
	ofstream out("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\코딩테스트연습\\파일입출력연습\\출력파일.txt");
	*/

	// class 또는 struct 자료형 입출력
	ifstream in("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\코딩테스트연습\\파일입출력연습\\클래스입력파일.txt");
	ofstream out("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\코딩테스트연습\\파일입출력연습\\클래스출력파일.txt");

	bool withclass = true;
	if (in.is_open())
	{
		cout << "파일이 존재" << endl;
#ifdef withSpace

		if (withclass)
		{
			vector<Test> v;

			Test t;
		}
		else
		{
			/**
			 * 공백 포함 -> 받을 때 char로 받아야 함.
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
				out <<"이름 : "<< t.GetName()<<" ";
				out <<"나이 : "<< t.GetAge()<<endl;
			}
		}
		else
		{
			/**
			 * 띄어쓰기 없음.
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
		cout << "파일이 존재하지 않음." << endl;
	}
	in.close();
	out.close();
}