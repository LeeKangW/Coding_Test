#include <string>
#include <vector>

using namespace std;

/** 
* 상당히 어려운 문제.
* DP로 풀어야 하는데, 문제가 너무 어려웠다...
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