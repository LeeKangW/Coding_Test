#include<iostream>
#include<thread>
#include<string>
#include<mutex>
#include<vector>

class Test
{
private:
	int n1 = 0;
	int n2 = 0;
	int sum = 0;
public:
	Test() = default;
	Test(int lhs, int rhs) :n1(lhs), n2(rhs) { sum = n1 + n2; }

	void show()const;
};
void Test::show() const
{
	printf("숫자1 : %d \n숫자2 : %d\n총계 : %d", n1, n2, sum);
}
void SettingField(Test& s,std::vector<Test>& v ,std::mutex& m)
{
	std::lock_guard<std::mutex> lock(m);
	for (int i = 0; i < 10; ++i)
	{
		v.emplace_back(i, i + 1);
	}
}

/// <summary>
/// lock_guard를 통해서 하나의 쓰레드가 계산을 담당할 수 있도록 함.
/// </summary>
/// <param name="count"></param>
/// <param name="m"></param>
void Add(int& count, std::mutex& m)
{
	std::lock_guard<std::mutex> lock(m);
	for (size_t i = 0; i < 100'000; ++i)
	{
		count += 1;
	}
}

int main()
{
#pragma region 뮤텍스를 이용
	/**
	 * 뮤텍스를 이용하여 하나의 스레드만 이용하게 lock 기능.
	 */
	int count = 0;
	std::vector<std::thread> tv;
	std::mutex m;
	for (size_t i = 0; i < 10; ++i)
	{
		tv.emplace_back(Add, std::ref(count), std::ref(m));
	}
	for (size_t i = 0; i < tv.size(); ++i)
	{
		tv[i].join();
	}

	std::cout << count << std::endl<<std::endl;
#pragma endregion

#pragma region 생성자 소비자 패턴
	std::vector<Test> v;
#pragma endregion


	
}