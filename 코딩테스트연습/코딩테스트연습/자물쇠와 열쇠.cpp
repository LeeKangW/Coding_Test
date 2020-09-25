#include <string>
#include <vector>

/**
* < ���� ��� >
* ũ�� ������� �ʰ�, Lock���� �� ū Lock�� �ְ�, Ű�� �ϳ��� �� �־�鼭 üũ�ϸ� �ȴ�.
* ���� ���ٸ�, Ű�� 90�� ȸ�� ��Ų ��, �ٽ� Lock�� ���纻��.
*
*
* < Ǫ�� ��� >
* 1. 90�� ȸ�� �����.
* 2. Lock �������� ��,��,��,�� Lock�� Key�� �ִ� ũ���� 20�� ������ش�. ( ��, Lock.size() + 40 )
* 3. newLock(2���� ���� ���� ���� Lock) �� newLock[20][20] ���� Lock�� ä���ش�. ( ��, ����� Lock�� ���� )
* 4. newLock�� 0,0 ���� �����ؼ�, Key ���� �ϳ��� �־��ش�.
* 5. 4�� ��, newLock[20][20] ( ��, ���� Lock�� �ִ� �� ) ���� 1�� �ƴ� ���� �ִ��� üũ. ( ������, false ��ȯ / ������ true ��ȯ )
* 6. ���� false��, 4 ~ 5 �� ��� ����
* 7. false�� ���·�, newLock�� ��ü�� �� ���ٸ�, key�� Rotation ���� �ش�.
* 8. ���� true��, true ��ȯ.
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