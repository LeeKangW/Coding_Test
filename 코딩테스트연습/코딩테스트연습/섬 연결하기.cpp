#include <string>
#include <vector>
#include <algorithm>

/** 
* �ּ� ���� Ʈ�� ���� -> ũ�罺Į�� ����� ���� ��������.
* @ Tips : https://yabmoons.tistory.com/186
* @ Link : https://programmers.co.kr/learn/courses/30/lessons/42861
*/ 


using namespace std;

int Find_Parent(int x, vector<int>& Parents)
{
    if (Parents[x] == x) return x;
    else return Parents[x] = Find_Parent(Parents[x], Parents);
}
bool Same_Parent(int x, int y, vector<int>& Parents)
{
    x = Find_Parent(x,Parents);
    y = Find_Parent(y,Parents);

    if (x == y) return true; // �θ� ���ٸ� ��, ����Ǿ��ٸ�
    else return false;
}

void Union(int x, int y, vector<int>& Parents)
{
    x = Find_Parent(x,Parents);
    y = Find_Parent(y,Parents);
    if (x != y)
    {
        Parents[y] = x; // ��� ���� ����� �θ� �ٸ� ���� ���� ����.
    } // �̰����� ���� ��� x�� �θ�, ��� y�� �θ� x�� ��������.
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b)
        {
            return a[2] < b[2];
        });
    vector<int> Parents(n, 0);
    for (int i = 0; i < Parents.size(); ++i)
    {
        Parents[i] = i;
    }

    for (int i = 0; i < costs.size(); ++i)
    {
        if (!Same_Parent(costs[i][0], costs[i][1], Parents))
        {
            Union(costs[i][0], costs[i][1],Parents);
            answer += costs[i][2];
        }
    }
    return answer;
}

int main()
{
    solution(4, { {0, 1, 5},{1, 2, 3},{2, 3, 3},{3, 1, 2},{3, 0, 4} });
}