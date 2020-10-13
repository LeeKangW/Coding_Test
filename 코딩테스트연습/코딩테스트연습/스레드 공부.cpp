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
	printf("����1 : %d \n����2 : %d\n�Ѱ� : %d", n1, n2, sum);
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
/// lock_guard�� ���ؼ� �ϳ��� �����尡 ����� ����� �� �ֵ��� ��.
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
#pragma region ���ؽ��� �̿�
	/**
	 * ���ؽ��� �̿��Ͽ� �ϳ��� �����常 �̿��ϰ� lock ���.
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

#pragma region ������ �Һ��� ����
	std::vector<Test> v;
#pragma endregion


	
}