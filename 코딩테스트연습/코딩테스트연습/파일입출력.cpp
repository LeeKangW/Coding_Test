#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	// Ÿ ��ο� ���� �� \ �� �ι��� �ʿ��ϴ�.
	ifstream in("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\�ڵ��׽�Ʈ����\\��������.txt");
	
	if (in.is_open())
	{
		cout << "������ ����" << endl;
		int c;
		while ((c = in.get()) != EOF)
		{
			cout << (char)c;
		}
	}
	else
	{
		cout << "������ �������� ����." << endl;
	}
	in.close();
}