#include <string>
#include <vector>

/** 
* @ Link : https://programmers.co.kr/learn/courses/30/lessons/42898
* 
* Tips
* 이동은 하,우 만 가능하기에, 
* 좌표의 왼,상에 좌표값이 집에서 그 좌표까지 가는 최단 코스의 수이면,
* 그 수들을 더해서 풀 수 있다. ( DP 이용 )
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
            // 물 웅덩이가 집의 x,y 축에 있으면, 웅덩이 이후에는 갈수가 없기에 다 0으로 세팅.
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
            if (board[j][i] != 0) // 웅덩이가 아니면
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