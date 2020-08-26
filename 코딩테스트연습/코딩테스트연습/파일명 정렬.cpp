#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool Compare(const string& a, const string& b) {
    string a_temp = "";
    string b_temp = "";
    size_t a_idx = 0,b_idx=0;
    for (; a_idx < a.size(); ++a_idx) {
        if (!isdigit(a[a_idx]))
            a_temp += tolower(a[a_idx]);
        else
            break;
    }
    for (; b_idx < b.size(); ++b_idx) {
        if (!isdigit(b[b_idx]))
            b_temp += tolower(b[b_idx]);
        else
            break;
    }
    if (a_temp != b_temp)
        return a_temp < b_temp;
    
    a_temp.clear(); b_temp.clear();

    for (; a_idx < a.size(); ++a_idx) {
        if (isdigit(a[a_idx]))
            a_temp += tolower(a[a_idx]);
        else
            break;
    }
    for (; b_idx < b.size(); ++b_idx) {
        if (isdigit(b[b_idx]))
            b_temp += tolower(b[b_idx]);
        else
            break;
    }
    size_t a_num = stoi(a_temp);
    size_t b_num = stoi(b_temp);
    if (a_num != b_num)
        return a_num < b_num;

    return false;
}

vector<string> solution(vector<string> files) {

    stable_sort(files.begin(), files.end(), Compare);
    return files;
}

int main() {
    vector<string> v = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };

    solution(v);
}