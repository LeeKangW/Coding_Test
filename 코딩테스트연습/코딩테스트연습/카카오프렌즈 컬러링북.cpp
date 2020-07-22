#include <vector>
#include<algorithm>
// ��ũ : https://programmers.co.kr/learn/courses/30/lessons/1829

using namespace std;

// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.
vector<vector<int>> pic;
bool check[100][100];
vector<int> count_area;
int idx;

void check_leftright(int row, int col, int temp) {
    // ���� ��(��������) ���� Ȯ��
    for (int i = col; i < pic[row].size(); ++i) {
        if (pic[row][i] == temp && !check[row][i]) {
            ++count_area[idx];
            check[row][i] = true;
        }
        else
            break;
    }
    // ���� ��(��������) Ȯ��
    for (int i = col - 1; i > 0; --i) {
        if (pic[row][i] == temp && !check[row][i]) {
            ++count_area[idx];
            check[row][i] = true;
        }
        else
            break;
    }
}


void check_area(int row,int col) {
    int temp = pic[row][col];
    int n = row;

    // �Ʒ��� �� �ȱ�.
    while (n < pic.size()) {
        if (pic[n][col] == temp) {
            check_leftright(n, col, temp);
            ++n;
        }
        else
            break;
    }
    n = row;
    // Ȥ�ó� ������ �ִٸ� �� �Ⱦ�����.
    while (n >= 0) {
        if (pic[n][col] == temp) {
            check_leftright(n, col, temp);
            --n;
        }
        else
            break;
    }

}


vector<int> solution(int m, int n, vector<vector<int>> picture) {
    count_area.clear();
    pic.clear(); pic.resize(picture.size());
    idx = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            check[i][j] = false;
        }
    }
    for (int i = 0; i < picture.size(); ++i) {
        for (int j = 0; j < picture[i].size(); ++j) {
            pic[i].push_back(picture[i][j]);
        }
    }

    int number_of_area = 0;
    int max_size_of_one_area = 0;

    for (int i = 0; i < pic.size();++i) {
        for (int j = 0; j < pic[i].size(); ++j) {
            if (pic[i][j] != 0 && !check[i][j]) {
                ++number_of_area;
                count_area.push_back(0);
                check_area(i, j);
                ++idx;
            }
        }
    }
   
    max_size_of_one_area = *(max_element(count_area.begin(), count_area.end()));
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}

int main() {
    vector<vector<int>> v = { {1,1,1,0},{1,2,2,0},{1,0,0,1},{0,0,0,1},{0,0,0,3},{0,0,0,3} };
    solution(6, 4, v);
}