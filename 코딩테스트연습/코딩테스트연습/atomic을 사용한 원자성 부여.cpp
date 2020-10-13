#include<iostream>
#include <atomic>
#include <thread>
#include<vector>
using namespace std;

/// <summary>
/// atmoic을 사용하여 원자성을 부여....
/// CPU가 하나의 스레드를 작동 중일 때 다른 스레드가 침범할 수 없게 한다.
/// 
/// 이를 통해, mutex의 lock 없이도 lock과 같은 효과를 낼 수 있다.
/// </summary>
/// <param name="count"></param>
void Add(atomic<int>& count)
{
	for (int i = 0; i < 1000'000; ++i)
	{
		count += 1;
	}
}

int main()
{
	atomic<int> count = 0;

	vector<thread> v;

	for (int i = 0; i < 100; ++i)
	{
		v.emplace_back(Add, ref(count));
	}
	for (int i = 0; i < v.size(); ++i)
	{
		v[i].join();
	}

	cout << count << endl;
}