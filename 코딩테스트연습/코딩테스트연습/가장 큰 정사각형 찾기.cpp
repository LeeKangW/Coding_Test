#include <iostream>
#include<vector>
#include<algorithm>
// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/12905
// ���� : https://devje8.tistory.com/6

// DP(Dynamic Programming)( ���� ��ȹ�� )���� Ǯ��� ��.
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int row = board[0].size(); // 4-4
    int col = board.size(); // 4-2
    for (int i = 1; i < col; i++) {
        for (int j = 1; j < row; j++) {
            //0�� ��쿡�� ���簢���� ��������� �����Ƿ� 1�� ��츸 ���
            if (board[i][j] == 1) {
                //������, ������, ���� �밢���� �ִ� �� �� ����
                board[i][j] = min(board[i][j - 1], board[i - 1][j]);
                board[i][j] = min(board[i - 1][j - 1], board[i][j]) + 1;
                answer = max(answer, board[i][j]);
            }
        }
    }
    // ������ �Ʒ����� ���� ���̸� ����Ǿ� �ֱ� ������ ���� ����
    return answer * answer;
}

int main() {
    vector<vector<int>> v = { {0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0} };
    solution(v);
}