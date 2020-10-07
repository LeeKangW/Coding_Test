#include <string>
#include <vector>

/** 
* @ Link : https://programmers.co.kr/learn/courses/30/lessons/42898
* 
* Tips
* �̵��� ��,�� �� �����ϱ⿡, 
* ��ǥ�� ��,�� ��ǥ���� ������ �� ��ǥ���� ���� �ִ� �ڽ��� ���̸�,
* �� ������ ���ؼ� Ǯ �� �ִ�. ( DP �̿� )
*/
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    int board[101][101];
    for (size_t i = 1; i <= n; ++i)
    {
        for (size_t j = 1; j <= m; ++j)
        {
            board[i][j] = 1;
        }
    }

    for (const vector<int>& v : puddles)
    {
        board[v[1]][v[0]] = 0;
        if (v[0] == 1)
        {
            // �� �����̰� ���� x,y �࿡ ������, ������ ���Ŀ��� ������ ���⿡ �� 0���� ����.
            for (int i = v[1]; i <= n; ++i)
                board[i][1] = 0; 
        }
        if (v[1] == 1)
        {
            for (int i = v[0]; i <= m; ++i)
            {
                board[1][i] = 0;
            }
        }
    }

    for (int i = 2; i <= m; ++i)
    {
        for (int j = 2; j <= n; ++j)
        {
            if (board[j][i] != 0) // �����̰� �ƴϸ�
            {
                board[j][i] = (board[j-1][i] + board[j][i-1]) % 1000000007;
            }
        }
    }

    answer = board[n][m];
    return answer;
}

int main()
{
    solution(4, 3, { {2,2} });
}