#include<iostream>
#include <string>
#include<stack>


/// <summary>
/// 괄호가 없는 후위표기법으로 바꾸는 함수
/// </summary>
/// <param name="str"> 계산식 </param>
/// <returns> 변환된 식 </returns>
std::string MakePostFixNotation(const std::string& str)
{
	std::stack<char> operators;
	std::string strTmp = ""; // 후위표기법으로 만들 string

	for (int i = 0; i < str.size(); ++i)
	{
		char c = str[i];
		if (isdigit(c)) // 숫자이면 붙인다.
		{
			strTmp += c;
		}
		else 
		{
			/**
			 * 우선순위를 따져서 처리한다.
			 * 1. 스택에 있는 연산자의 우선순위가 같거나 크다면 스택에 있는 연산자를 pop한 후 출력하고 현재 연산자는 스택에 push.
			 * 2. 우선순위가 현재 연산자가 더 크다면 연산자를 push한다. ( 스택을 pop 하지 않음 . )
			 * 
			 * 연산자 우선순위
			 * 우선순위 낮음 -> 우선순위 높음
			 *	( -> + - -> * / ->  
			 */
			if (operators.empty()) // 비어있으면, 넣어버린다.
			{
				operators.push(c);
			}
			else
			{
				char stacksOper = operators.top();

				switch (c)
				{
				case '+':
				case '-':
				{
					switch (stacksOper)
					{
					case '+':
					case '-':
					case '*':
					case '/': // 연산순위가 같거나 더 크다면
						strTmp += stacksOper;
						operators.pop();
						operators.push(c);
						break;
					}
					break;
				}

				case '*':
				case '/':
				{
					switch (stacksOper)
					{
					case '+':
					case '-': // 스택의 연산자가 더 작다면
						operators.push(c);
						break;
					case '*':
					case '/': // 연산순위가 같다면
						strTmp += stacksOper;
						operators.pop();
						operators.push(c);
						break;
					}
					break;
				}
					break;
				}
			}
		}
	}

	while (!operators.empty()) // 남은 연산자들을 뒤에 붙여준다.
	{
		char c = operators.top();
		strTmp += c;
		operators.pop();
	}

	return strTmp;
}


/// <summary>
/// 괄호가 있는 계산식을 후위표기법으로 바꾸는 함수
/// </summary>
/// <param name="str"> 계산식 </param>
/// <returns> 변환된 식 </returns>
std::string MakePostFixNotationWithBracket(const std::string& str)
{
	std::stack<char> operators;
	std::string strTmp = ""; // 후위표기법으로 만들 string

	for (int i = 0; i < str.size(); ++i)
	{
		char c = str[i];
		if (isdigit(c)) // 숫자이면 붙인다.
		{
			strTmp += c;
		}
		else
		{
			/**
			 * 우선순위를 따져서 처리한다.
			 * 1. 여는 괄호가 있으면 무조건 push.
			 * 2. 스택에 있는 연산자의 우선순위가 같거나 크다면 스택에 있는 연산자를 pop한 후 출력하고 현재 연산자는 스택에 push.
			 * 3. 우선순위가 현재 연산자가 더 크다면 연산자를 push한다. ( 스택을 pop 하지 않음 . )
			 * 4. 닫는 괄호가 나오면 여는 괄호가 나올때까지 모든 연산자를 후위표기법식에 붙인다. ( 여는 괄호는 붙이지 않음. )
			 * 
			 * 연산자 우선순위
			 * 우선순위 낮음 -> 우선순위 높음
			 *	( -> + - -> * / ->
			 */
			if (operators.empty() || c == '(') // 비어있으면, 넣어버린다.
			{
				operators.push(c);
			}
			else
			{
				char stacksOper = operators.top();

				switch (c)
				{
				case '+':
				case '-':
				{
					switch (stacksOper)
					{
					case '(':
						operators.push(c);
						break;
					case '+':
					case '-':
					case '*':
					case '/': // 연산순위가 같거나 더 크다면
						strTmp += stacksOper;
						operators.pop();
						operators.push(c);
						break;
					}
					break;
				}

				case '*':
				case '/':
				{
					switch (stacksOper)
					{
					case '(':
					case '+':
					case '-': // 스택의 연산자가 더 작다면
						operators.push(c);
						break;
					case '*':
					case '/': // 연산순위가 같다면
						strTmp += stacksOper;
						operators.pop();
						operators.push(c);
						break;
					}
					break;
				}

				case ')':
				{
					while (!operators.empty()) // 스택의 탑이 여는 괄호일 때까지 확인.
					{
						char topCharc = operators.top();

						if (topCharc == '(') // 여는거였다면, pop하고 while문을 탈 출.
						{
							operators.pop();
							break;
						}
						else
						{
							strTmp += topCharc;
							operators.pop();
						}
					}
				}
				break;
				}
			}
		}
	}

	while (!operators.empty()) // 남은 연산자들을 뒤에 붙여준다.
	{
		char c = operators.top();
		strTmp += c;
		operators.pop();
	}

	return strTmp;
}


/// <summary>
/// 후위표기법을 계산
/// </summary>
/// <param name="str"> 후위표기법 계산식 </param>
/// <returns> 계산된 값 </returns>
int Calculation(const std::string& str)
{
	std::stack<int> nonOpers;

	for (int i = 0; i < str.size(); ++i)
	{
		char c = str[i];
		if (isdigit(c))
		{
			nonOpers.push(c - '0');
		}
		else
		{
			if(nonOpers.empty()) // 예외처리
				continue;

			int n1 = nonOpers.top(); nonOpers.pop();
			int n2 = nonOpers.top(); nonOpers.pop();
			switch (c)
			{
			case '+':
				nonOpers.push(n1 + n2);
				break;
			case '-':
				nonOpers.push(n1 - n2);
				break;
			case '*':
				nonOpers.push(n1 * n2);
				break;
			case '/':
				if(n2 != 0)
					nonOpers.push(n1 / n2);
				break;
			}
		}
	}

	
	return nonOpers.top();
}

int main()
{
	std::string calcul = "1+2*3";
	std::string calculwithBracket = "(1+2)*(3+4)";

	calcul = MakePostFixNotation(calcul);
	calculwithBracket = MakePostFixNotationWithBracket(calculwithBracket);

	std::cout << calcul << std::endl;
	std::cout << calculwithBracket << std::endl;

	std::cout << Calculation(calcul) << std::endl;
	std::cout << Calculation(calculwithBracket) << std::endl;
}