#include<iostream>
#include<string>

int main()
{
	int input;

	while (true)
	{
		// std::cin.setf(std::ios_base::hex, std::ios_base::basefield); //-> 16���� �Է��� ���� �� ����.

		std::cin >> std::hex >> input; // <- �� ������ε� 16���� �Է��� ���� �� �ִ�.
		//std::cin >> input;
		std::cout << "�Է�::" << input << std::endl;

		if (std::cin.fail())
		{
			std::cout << "����� �Է����ּ���." << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}
}