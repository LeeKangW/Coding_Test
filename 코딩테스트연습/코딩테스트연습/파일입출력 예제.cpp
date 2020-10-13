#include<iostream>
#include<fstream>
#include<random>
#include<array>
#include<map>
#include<thread>
#include<mutex>
#include<queue>

void FileOpen(std::ifstream& in,std::string fileName)
{
	if (in.is_open())
		in.close();

	std::string path = "C:\\Users\\user\\Desktop\\C++\\Coding_Test\\�ڵ��׽�Ʈ����\\��������¿���\\" + fileName;
	in.open(path);
}
void MakeFile(std::ofstream& out, std::string fileName)
{
	if (out.is_open())
		out.close();

	std::string path = "C:\\Users\\user\\Desktop\\C++\\Coding_Test\\�ڵ��׽�Ʈ����\\��������¿���\\" + fileName;
	out.open(path);
}

void CountNum(std::map<int,int>& m,int& what_num)
{
	m[what_num]++;
}

int main()
{
	std::ifstream in;
	
	FileOpen(in, "��������� ����1.txt");

	std::map<int, int> m;
	std::queue<int> q;
	if (in)
	{
		printf("������ �����մϴ�.\n");

		int n;

		std::vector<std::thread> v(1000000);

		while (!in.eof())
		{
			in >> n;
			CountNum(m, n);
		}
		
		for (auto it = m.begin(); it != m.end(); ++it)
		{
			std::cout << it->first << " : " << it->second << std::endl;
		}
	}
	else
	{
		std::ofstream out;
		MakeFile(out, "��������� ����1.txt");

		std::random_device rd;
		std::mt19937 gen(rd());

		std::uniform_int_distribution<int> dis(0, 9);

		std::cout << "������ �������� �ʾ�, ������ ���� ����" << std::endl;

		for (int i = 0; i < 1000000; ++i)
		{
			out << dis(gen) << " ";
		}

		std::cout << "���� ���� �Ϸ�" << std::endl;
	}
}