#include<iostream>
#include<string>
#include<array>

int main()
{
	// 1���� �迭 ���� -> �ּҷ� ����
	std::array<int, 5> arr{ 1,2,3,4,5 };

	int* arr_ptr = arr.data();

	for (int i = 0; i < arr.size(); ++i)
	{
		std::cout << *(arr_ptr + i) << std::endl;
	}
	std::cout << std::endl;

	// 2���� �迭 ����
	int arr2[2][2]{ {1,2},{3,4} };

	for (int i = 0; i < 2; ++i)
	{
		int* arr2_ptr = arr2[i];

		for (int j = 0; j < 2; ++j)
		{
			std::cout << *(arr2_ptr + j) << std::endl;
		}
	}


}