#include <string>
#include <vector>

using namespace std;

// �׳� �Ǻ���ġ ����

int solution(int n)
{
    vector<int> p(60001, 0);
    p[1] = 1;
    p[2] = 2;

    for (size_t i = 3; i <= n; i++)
    {
        p[i] = p[i - 1] + p[i - 2];
    }
    return p[n];
}

int main()
{
    solution(4);
}