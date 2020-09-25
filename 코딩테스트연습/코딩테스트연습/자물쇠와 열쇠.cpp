#include <string>
#include <vector>

/**
* < 접근 방법 >
* 크게 고민하지 않고, Lock보다 더 큰 Lock이 있고, 키를 하나씩 다 넣어보면서 체크하면 된다.
* 만약 없다면, 키를 90도 회전 시킨 후, 다시 Lock에 맞춰본다.
*
*
* < 푸는 방법 >
* 1. 90도 회전 만들기.
* 2. Lock 기준으로 상,하,좌,우 Lock과 Key의 최대 크기인 20씩 만들어준다. ( 즉, Lock.size() + 40 )
* 3. newLock(2번을 통해 새로 만든 Lock) 에 newLock[20][20] 부터 Lock을 채워준다. ( 즉, 가운데에 Lock을 생성 )
* 4. newLock의 0,0 부터 시작해서, Key 값을 하나씩 넣어준다.
* 5. 4번 후, newLock[20][20] ( 즉, 실제 Lock이 있는 곳 ) 부터 1이 아닌 것이 있는지 체크. ( 있으면, false 반환 / 없으면 true 반환 )
* 6. 만약 false면, 4 ~ 5 을 계속 진행
* 7. false인 상태로, newLock의 전체를 다 돈다면, key를 Rotation 시켜 준다.
* 8. 만약 true면, true 반환.
*
* @See : https://programmers.co.kr/learn/courses/30/lessons/60059
*/
using namespace std;

void KeyRotation(vector<vector<int>>& key)
{
	size_t M = key.size();
	vector<vector<int> > tmp(M, vector<int>(M, 0));
	for (size_t i = 0; i < M; i++)
		for (size_t j = 0; j < M; j++)
			tmp[j][M - i - 1] = key[i][j];
	key = tmp;
}
bool MatchLock(size_t row, size_t col, vector<vector<int>>& key, vector<vector<int>> newLock, const vector<vector<int>>& lock)
{
	size_t M = key.size();
	size_t newN = newLock.size();

	for (size_t i = 0; i < M; ++i)
	{
		for (size_t j = 0; j < M; ++j)
		{
			if (row + i < newN && col + j < newN)
				newLock[row + i][col + j] += key[i][j];
			else
				break;
		}
	}

	size_t N = lock.size();
	for (size_t i = 20; i < 20 + N; ++i)
	{
		for (size_t j = 20; j < 20 + N; ++j)
		{
			if (newLock[i][j] != 1)
				return false;
		}
	}

	return true;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
	vector<vector<int>> newLock(lock.size() + 40, vector<int>(lock.size() + 40, 0));

	for (size_t i = 20; i < 20 + lock.size(); ++i)
	{
		for (size_t j = 20; j < 20 + lock.size(); ++j)
		{
			size_t lock_row = i - 20;
			size_t lock_col = j - 20;
			newLock[i][j] = lock[lock_row][lock_col];
		}
	}

	int N = newLock.size();
	size_t rotationCount = 0;
	while (rotationCount < 4)
	{
		for (size_t i = 0; i < N; ++i)
		{
			for (size_t j = 0; j < N; ++j)
			{
				if (MatchLock(i, j, key, newLock, lock))
					return true;
			}
		}
		KeyRotation(key);
		rotationCount += 1;
	}

	return false;
}

int main()
{
	solution({ {0,0,0},{1,0,0},{0,1,1} }, { {1,1,1},{1,1,0},{1,0,1} });
}