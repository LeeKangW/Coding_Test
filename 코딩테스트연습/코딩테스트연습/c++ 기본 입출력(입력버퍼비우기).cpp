#include<iostream>
#include<string>

int main()
{
	int input;

	while (true)
	{
		// std::cin.setf(std::ios_base::hex, std::ios_base::basefield); //-> 16진수 입력을 받을 수 있음.

		std::cin >> std::hex >> input; // <- 이 방법으로도 16진수 입력을 받을 수 있다.
		//std::cin >> input;
		std::cout << "입력::" << input << std::endl;

		if (std::cin.fail())
		{
			std::cout << "제대로 입력해주세요." << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
		}
	}
}