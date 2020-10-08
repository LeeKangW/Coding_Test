#include <string>
#include <vector>
#include <iostream>
using namespace std;

/** 
* 쉽게 생각하면 되는 거였지만, 너무 어렵게 생각한 문제...
* 
* 1. 곱셈이 최댓값이어야 한다.
*  -> 나오는 숫자 값이 서로 차이가 없어야 한다. ( 즉 비슷한 값들 )
* 
* 2. 숫자 S를 N개로 만들 수 있어야 한다.
*  
* 2를 만족하면서 1도 만족하려면,
* S를 N으로 나눈 숫자로 구성된 것이면 된다.
* -> 이러면, 서로 비슷한 값들로 구성이 되기 때문. ( 곱이 최대다. )
* 
* 그 후 , S % N 값을 하나씩 더해주면 된다.
* 
* 즉,
* 
* S = 10
* N = 3 이면
* 10 / 3 =3 이고, 10 % 3 = 1이다.
* 그럼
* 일단 { 3,3,3} 으로 S / N 값을 N개로 맞추고
* 
* 10 % 3 = 1이기에, 맨 뒤부터 더해주면 되는데,
* 1이기에 하나만 더해주면 된다.
* 그래서 정답은 {3,3,4} 이다.
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