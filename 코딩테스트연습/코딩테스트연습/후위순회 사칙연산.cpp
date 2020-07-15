#include<iostream>
#include<string>
#include<iostream>
#include<stack>
using namespace std;

// 참고한 링크 : https://penglog.tistory.com/99

int calculation(int n1, int n2, char c) {
	switch (c)
	{
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	case '/':
		return n2 / n1;
	}
}
int solution(string s) {

	stack<char> nums;
	stack<char> opers;

	for (char c : s) {
		if (isdigit(c)) {
			nums.push(c);
		}
		else {
			if (opers.empty())
				opers.push(c);
			else {
				if (c == '+' || c == '-') {
					while (opers.top() == '*' || opers.top() == '/') {
						if (opers.empty()) break;
						int n1 = nums.top() - '0'; nums.pop();
						int n2 = nums.top() - '0'; nums.pop();
						nums.push(calculation(n1, n2, opers.top()) + '0');
						opers.pop();
					}
					opers.push(c);
				}
				else {
					char oper = opers.top();
					switch (oper)
					{
					case '+':
					case '-':
						opers.push(c);
						break;
					case '*':
					case '/':
						while (opers.top() == '*' || opers.top() == '/') {
							if (opers.empty()) break;
							int n1 = nums.top() - '0'; nums.pop();
							int n2 = nums.top() - '0'; nums.pop();
							nums.push(calculation(n1, n2, opers.top()) + '0');
							opers.pop();
						}
						opers.push(c);
						break;
					}
				}
			}
		}
	}

	while(!nums.empty()){
		if (nums.size() < 2)
			break;
		int n1 = nums.top() - '0'; nums.pop();
		int n2 = nums.top() - '0'; nums.pop();
		nums.push(calculation(n1, n2, opers.top()) + '0');
		opers.pop();
	}

	return nums.top() - '0';
}
int main() {

	cout << solution("2+3*2+3/3*2") << endl;
}