#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int main()
{
	// 타 경로에 있을 때 \ 는 두번이 필요하다.
	ifstream in("C:\\Users\\user\\Desktop\\C++\\Coding_Test\\코딩테스트연습\\예시파일.txt");
	
	if (in.is_open())
	{
		cout << "파일이 존재" << endl;
		int c;
		while ((c = in.get()) != EOF)
		{
			cout << (char)c;
		}
	}
	else
	{
		cout << "파일이 존재하지 않음." << endl;
	}
	in.close();
}