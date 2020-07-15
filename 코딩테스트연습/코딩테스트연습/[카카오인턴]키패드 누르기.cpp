#include <string>
#include <vector>

// ¸µÅ© : https://programmers.co.kr/learn/courses/30/lessons/67256

using namespace std;

int keypad[4][3] = {
       1,2,3,
       4,5,6,
       7,8,9,
       -1,0,-2
};
pair<int, int> hand_pos(int hand) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (keypad[i][j] == hand)
                return make_pair(i, j);
        }
    }
}
string choose_hand(int& n,int& last_left,int& last_right,string& hand) {
    pair<int, int> left = hand_pos(last_left);
    pair<int, int> right = hand_pos(last_right);
    pair<int, int> keypad = hand_pos(n);

    
    right.first -= keypad.first; right.second -= keypad.second;
    left.first -= keypad.first; left.second -= keypad.second;

    if (abs(right.first) + abs(right.second) > abs(left.first) + abs(left.second)) {
        last_left = n;
        return "L";
    }
    else if (abs(right.first) + abs(right.second) == abs(left.first) + abs(left.second)) {
        if (hand == "left")
        {
            last_left = n;
            return "L";
        }
        else {
            last_right = n;
            return "R";
        }
    }
    else {
        last_right = n;
        return "R";
    }
}
string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_num=-1, right_num=-2;
    for (int n : numbers) {
        switch (n)
        {
        case 1:
        case 4:
        case 7:
            left_num = n;
            answer += "L";
            break;
        case 3:
        case 6:
        case 9:
            right_num = n;
            answer += "R";
            break;
        default:
            answer +=choose_hand(n, left_num, right_num, hand);
            break;
        }
    }
    return answer;
}
