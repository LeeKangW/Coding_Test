#include <string>
#include <iostream>

//¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/12916

using namespace std;


bool solution(string s)
{
    bool answer = true;
    int s_count = 0;
    int p_count = 0;
    
    for (char& c : s) {
        if (tolower(c) == 'y')
            ++s_count;
        else if (tolower(c) == 'p')
            ++p_count;
    }
    
    if (s_count == p_count)
        answer = true;
    else if (s_count == 0 && p_count == 0)
        answer = false;
    else
        answer = false;

    return answer;
}