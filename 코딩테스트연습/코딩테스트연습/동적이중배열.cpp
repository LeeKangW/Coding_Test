#include<iostream>
#include<string>

using namespace std;

/// <summary>
/// 2���� �����迭 �����ϴ� �� ����.
/// </summary>
/// <returns></returns>
int main()
{
	int col = 0;
	int row = 0;

	cout << "�� ũ�⸦ �����ּ���. : ";
	cin >> col;

	cout << "�� ũ�⸦ �����ּ���. :";
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