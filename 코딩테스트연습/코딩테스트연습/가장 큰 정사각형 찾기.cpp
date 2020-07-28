#include <iostream>
#include<vector>
#include<algorithm>
// 링크 : https://programmers.co.kr/learn/courses/30/lessons/12905
// 참고 : https://devje8.tistory.com/6

// DP(Dynamic Programming)( 동적 계획법 )으로 풀어야 함.
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int row = board[0].size(); // 4-4
    int col = board.size(); // 4-2
    for (int i = 1; i < col; i++) {
        for (int j = 1; j < row; j++) {
            //0인 경우에는 정사각형이 만들어지지 않으므로 1인 경우만 계산
            if (board[i][j] == 1) {
                //왼쪽점, 위쪽점, 왼쪽 대각선에 있는 점 비교 수행
                board[i][j] = min(board[i][j - 1], board[i - 1][j]);
                board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }
    // 오른쪽 아래에는 변의 길이만 저장되어 있기 때문에 제곱 수행
    return answer * answer;
}

int main() {
    vector<vector<int>> v = { {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} };
    solution(v);
}