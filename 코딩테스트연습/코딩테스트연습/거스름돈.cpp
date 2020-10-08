#include <string>
#include <vector>

using namespace std;

/** 
* ����� ����� ����.
* DP�� Ǯ��� �ϴµ�, ������ �ʹ� �������...
* 
* @ See : https://tosuccess.tistory.com/57
* 
* @ Link : https://programmers.co.kr/learn/courses/30/lessons/12907
*/
int solution(int n, vector<int> money)
{
	int* a = new int[100000]{ 0, };
	a[0] = 1;

	for (const int& i : money)
	{
		for (int j = i; j <= n; ++j)
		{
			a[j] += a[j - i];
		}
	}

	return a[n];
}