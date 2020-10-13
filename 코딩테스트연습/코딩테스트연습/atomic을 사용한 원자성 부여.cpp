#include<iostream>
#include <atomic>
#include <thread>
#include<vector>
using namespace std;

/// <summary>
/// atmoic�� ����Ͽ� ���ڼ��� �ο�....
/// CPU�� �ϳ��� �����带 �۵� ���� �� �ٸ� �����尡 ħ���� �� ���� �Ѵ�.
/// 
/// �̸� ����, mutex�� lock ���̵� lock�� ���� ȿ���� �� �� �ִ�.
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