#include<iostream>
#include<string>

using namespace std;

/// <summary>
/// 2차원 동적배열 생성하는 법 연습.
/// </summary>
/// <returns></returns>
int main()
{
	int col = 0;
	int row = 0;

	cout << "행 크기를 적어주세요. : ";
	cin >> col;

	cout << "열 크기를 적어주세요. :";
	cin >> row;

	string** str = new string * [col];

	for (int i = 0; i < col; ++i)
	{
		str[i] = new string[row];
	}

	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			str[i][j] = to_string(i) + ", " + to_string(j);
		}
	}

	for (int i = 0; i < col; ++i)
	{
		for (int j = 0; j < row; ++j)
		{
			cout << str[i][j] << endl;
		}
	}
}