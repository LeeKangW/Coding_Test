#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/42577

using namespace std;

bool solution(vector<string> phone_book) {
    for (int i = 0; i < phone_book.size(); ++i) {
        for (int j = 0; j < phone_book.size(); ++j) {
            if (i == j)continue;
            if (phone_book[j].size() < phone_book[i].size())
                continue;
            string temp = phone_book[j].substr(0, phone_book[i].size());
            if (phone_book[i] == temp) {
                return false;
                break;
            }
        }
    }
    return true;
}