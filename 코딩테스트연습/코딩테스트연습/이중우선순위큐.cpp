#include <string>
#include <vector>
#include <algorithm>
/** 
* @See : https://programmers.co.kr/learn/courses/30/lessons/42628
*/
using namespace std;

void DeleteNum(vector<int>& v, const string& s)
{
    if (v.empty()) return;
    string str = "";
    for (size_t i = 2; i < s.size(); ++i)
        str += s[i];

    if (str == "1")
    {
        v.erase(--v.end());
    }
    else
    {
        v.erase(v.begin());
    }
}
void InsertNum(vector<int>& v, int num)
{
    v.push_back(num);
    sort(v.begin(), v.end());
}

vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    vector<int> vector;

    for (const string& str : operations)
    {
        char c = str[0];
        string sTmp = "";
        bool isNegative = false;
        int num = 0;
        switch (c)
        {
        case 'I':
            
            for (size_t i = 2; i < str.size(); ++i)
            {
                
                if (isdigit(str[i]))
                    sTmp += str[i];
                else
                {
                    if (str[i] == '-')
                        isNegative = true;
                }
            }
            num = stoi(sTmp);
            if (isNegative)
                num *= -1;
            InsertNum(vector, num);
            break;
        case 'D':
            DeleteNum(vector, str);
            break;
        default:
            break;
        }
    }
    if (vector.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(*(--vector.end()));
        answer.push_back(*(vector.begin()));
        
    }
    return answer;
}
int main()
{
   // solution({ "I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1" });
    solution({ "I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333" });
}