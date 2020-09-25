#include <string>
#include <vector>

using namespace std;

void SetLeftDown(vector<vector<int>>& shape,int n)
{
    for (size_t i = 0; i < shape.size(); ++i)
    {
        shape[i][0] = (i + 1);
    }

    for (size_t i = 0; i < n; ++i)
        shape[n - 1][i] = shape[n - 1][0] + (i + 1);
}
vector<int> solution(int n)
{
    vector<int> answer;
    vector<vector<int>> shape; shape.resize(n);

    SetLeftDown(shape, n);


    return answer;
}