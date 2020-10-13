#include<iostream>
#include<fstream>
#include<string>
#include <vector>
#include<thread>
#include<mutex>

class Test
{
private:
	std::string Name = "";
	int age = 0;

public:
	Test() = default;
	Test(std::string name, int p_age) :Name(name), age(p_age) {}

	void SetName(std::string name) { Name = name; }
	void SetAge(int age) { this->age = age; }

	std::string GetName() const
	{
		return Name;
	}
	int GetAge() const { return age; }


	void show() const
	{
		std::cout << "이름 : " << Name << ", 나이 : " << age << std::endl;
	}
};

void Settting(std::ifstream& in,std::vector<Test>& v,std::mutex& m)
{
	std::lock_guard<std::mutex> lock(m);
	if (in)
	{
		std::string str;

		// 공백 기준으로 in >> ?? -> ?? 에 들어가는 변수의 자료형에 맞추어 변환되어 나온다.
		while (!in.eof())
		{
			Test t;
			in >> str;
			t.SetName(str);
			in >> str;
			t.SetAge(stoi(str));
			v.push_back(t);
		}
	}
}

int main()
{
	std::ifstream in("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\코딩테스트연습\\파일입출력연습\\클래스입력파일.txt");
	std::ofstream out("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\코딩테스트연습\\파일입출력연습\\클래스출력파일2.txt");
	std::vector<Test> v;

	std::thread t1(Settting,std::ref(in),std::ref(v));

	t1.join();

	for (Test& t : v)
	{
		t.show();
	}
}