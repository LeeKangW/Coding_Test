#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12918

using namespace std;

bool solution(string s) {
    bool answer = true;
    if (s.size() == 4 || s.size() == 6) 
    {
        for (const char& c : s) 
        {
            if (isalpha(c)) 
            {
                answer = false;
                break;
            }
        }
    }
    else 
    {
        answer = false;
    }
    return answer;
}