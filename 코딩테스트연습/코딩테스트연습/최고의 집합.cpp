#include <string>
#include <vector>
#include <iostream>
using namespace std;

/** 
* ���� �����ϸ� �Ǵ� �ſ�����, �ʹ� ��ư� ������ ����...
* 
* 1. ������ �ִ��̾�� �Ѵ�.
*  -> ������ ���� ���� ���� ���̰� ����� �Ѵ�. ( �� ����� ���� )
* 
* 2. ���� S�� N���� ���� �� �־�� �Ѵ�.
*  
* 2�� �����ϸ鼭 1�� �����Ϸ���,
* S�� N���� ���� ���ڷ� ������ ���̸� �ȴ�.
* -> �̷���, ���� ����� ����� ������ �Ǳ� ����. ( ���� �ִ��. )
* 
* �� �� , S % N ���� �ϳ��� �����ָ� �ȴ�.
* 
* ��,
* 
* S = 10
* N = 3 �̸�
* 10 / 3 =3 �̰�, 10 % 3 = 1�̴�.
* �׷�
* �ϴ� { 3,3,3} ���� S / N ���� N���� ���߰�
* 
* 10 % 3 = 1�̱⿡, �� �ں��� �����ָ� �Ǵµ�,
* 1�̱⿡ �ϳ��� �����ָ� �ȴ�.
* �׷��� ������ {3,3,4} �̴�.
*
* @ Link : https://programmers.co.kr/learn/courses/30/lessons/12938
*/
vector<int> solution(int n, int s)
{
	vector<int> answer;

	if (n > s)
	{
		answer.push_back(-1);
		return answer;
	}

	int divide = s / n;
	int mod = s % n;
	int num = 0;
	if (mod != 0) num = 1;

	for (int i = 0; i < n; ++i)
	{
		answer.push_back(divide);
	}

	if (num != 0)
	{
		for (int i = mod; i > 0; --i)
		{
			answer[(answer.size() - 1) - (mod - i)] += num;
		}
	}

	return answer;
}