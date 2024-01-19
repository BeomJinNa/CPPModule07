#include "Array.hpp"
#include <iostream>

int	main(void)
{
	Array<int> emptyArray;
	std::cout << "기본 생성된 배열의 크기: " << emptyArray.size() << std::endl;

	Array<int> sizedArray(5);
	std::cout << "지정된 크기의 배열 크기: " << sizedArray.size() << std::endl;


	std::cout << "\n배열 요소 할당 및 출력 테스트:" << std::endl;
	for (unsigned int i = 0; i < sizedArray.size(); ++i)
	{
		sizedArray[i] = i * 10;
		std::cout << sizedArray[i] << " ";
	}
	std::cout << std::endl << std::endl;

	Array<int> copiedArray = sizedArray;
	std::cout << "복사된 배열의 크기: " << copiedArray.size() << std::endl;

	Array<int> assignedArray; assignedArray = copiedArray;
	std::cout << "할당된 배열의 크기: " << assignedArray.size() << std::endl;

	std::cout << "배열 요소 접근 테스트:" << std::endl;
	for (unsigned int i = 0; i < assignedArray.size(); ++i)
	{
		std::cout << "원소 " << i << ": " << assignedArray[i] << std::endl;
	}

	std::cout << std::endl;

	const Array<int> constArray = sizedArray;
	std::cout << "const 배열의 첫 번째 원소: " << constArray[0] << std::endl;

	try
	{
		std::cout << "범위를 벗어난 원소 접근 시도: " << constArray[10] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "예외 발생: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "크기가 0인 배열의 원소 접근 시도: " << emptyArray[0] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "예외 발생: " << e.what() << std::endl;
	}

	return (0);
}
