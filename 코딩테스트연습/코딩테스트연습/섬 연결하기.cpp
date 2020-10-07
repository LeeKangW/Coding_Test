#include <string>
#include <vector>
#include <algorithm>

/** 
* 최소 신장 트리 문제 -> 크루스칼로 만드는 법을 숙지하자.
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

    if (x == y) return true; // 부모가 같다면 즉, 연결되었다면
    else return false;
}

void Union(int x, int y, vector<int>& Parents)
{
    x = Find_Parent(x,Parents);
    y = Find_Parent(y,Parents);
    if (x != y)
    {
        Parents[y] = x; // 어느 한쪽 노드의 부모를 다른 한쪽 노드로 변경.
    } // 이과정을 통해 노드 x의 부모도, 노드 y의 부모도 x로 같아진다.
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