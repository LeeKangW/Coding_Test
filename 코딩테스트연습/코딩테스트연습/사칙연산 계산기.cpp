#include<iostream>
#include <string>
#include<stack>


/// <summary>
/// ��ȣ�� ���� ����ǥ������� �ٲٴ� �Լ�
/// </summary>
/// <param name="str"> ���� </param>
/// <returns> ��ȯ�� �� </returns>
std::string MakePostFixNotation(const std::string& str)
{
	std::stack<char> operators;
	std::string strTmp = ""; // ����ǥ������� ���� string

	for (int i = 0; i < str.size(); ++i)
	{
		char c = str[i];
		if (isdigit(c)) // �����̸� ���δ�.
		{
			strTmp += c;
		}
		else 
		{
			/**
			 * �켱������ ������ ó���Ѵ�.
			 * 1. ���ÿ� �ִ� �������� �켱������ ���ų� ũ�ٸ� ���ÿ� �ִ� �����ڸ� pop�� �� ����ϰ� ���� �����ڴ� ���ÿ� push.
			 * 2. �켱������ ���� �����ڰ� �� ũ�ٸ� �����ڸ� push�Ѵ�. ( ������ pop ���� ���� . )
			 * 
			 * ������ �켱����
			 * �켱���� ���� -> �켱���� ����
			 *	( -> + - -> * / ->  
			 */
			if (operators.empty()) // ���������, �־������.
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
					case '/': // ��������� ���ų� �� ũ�ٸ�
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
					case '-': // ������ �����ڰ� �� �۴ٸ�
						operators.push(c);
						break;
					case '*':
					case '/': // ��������� ���ٸ�
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

	while (!operators.empty()) // ���� �����ڵ��� �ڿ� �ٿ��ش�.
	{
		char c = operators.top();
		strTmp += c;
		operators.pop();
	}

	return strTmp;
}


/// <summary>
/// ��ȣ�� �ִ� ������ ����ǥ������� �ٲٴ� �Լ�
/// </summary>
/// <param name="str"> ���� </param>
/// <returns> ��ȯ�� �� </returns>
std::string MakePostFixNotationWithBracket(const std::string& str)
{
	std::stack<char> operators;
	std::string strTmp = ""; // ����ǥ������� ���� string

	for (int i = 0; i < str.size(); ++i)
	{
		char c = str[i];
		if (isdigit(c)) // �����̸� ���δ�.
		{
			strTmp += c;
		}
		else
		{
			/**
			 * �켱������ ������ ó���Ѵ�.
			 * 1. ���� ��ȣ�� ������ ������ push.
			 * 2. ���ÿ� �ִ� �������� �켱������ ���ų� ũ�ٸ� ���ÿ� �ִ� �����ڸ� pop�� �� ����ϰ� ���� �����ڴ� ���ÿ� push.
			 * 3. �켱������ ���� �����ڰ� �� ũ�ٸ� �����ڸ� push�Ѵ�. ( ������ pop ���� ���� . )
			 * 4. �ݴ� ��ȣ�� ������ ���� ��ȣ�� ���ö����� ��� �����ڸ� ����ǥ����Ŀ� ���δ�. ( ���� ��ȣ�� ������ ����. )
			 * 
			 * ������ �켱����
			 * �켱���� ���� -> �켱���� ����
			 *	( -> + - -> * / ->
			 */
			if (operators.empty() || c == '(') // ���������, �־������.
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
					case '/': // ��������� ���ų� �� ũ�ٸ�
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
					case '-': // ������ �����ڰ� �� �۴ٸ�
						operators.push(c);
						break;
					case '*':
					case '/': // ��������� ���ٸ�
						strTmp += stacksOper;
						operators.pop();
						operators.push(c);
						break;
					}
					break;
				}

				case ')':
				{
					while (!operators.empty()) // ������ ž�� ���� ��ȣ�� ������ Ȯ��.
					{
						char topCharc = operators.top();

						if (topCharc == '(') // ���°ſ��ٸ�, pop�ϰ� while���� Ż ��.
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

	while (!operators.empty()) // ���� �����ڵ��� �ڿ� �ٿ��ش�.
	{
		char c = operators.top();
		strTmp += c;
		operators.pop();
	}

	return strTmp;
}


/// <summary>
/// ����ǥ����� ���
/// </summary>
/// <param name="str"> ����ǥ��� ���� </param>
/// <returns> ���� �� </returns>
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
			if(nonOpers.empty()) // ����ó��
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