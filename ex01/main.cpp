#include <iostream>
#include "iter.hpp"

void	test_print_int(int num)
{
	std::cout << num << std::flush;
}

int	main(void)
{
	int			array[5] = {1,2,3,4,5};
	const int	carray[5] = {1,2,3,4,5};

	iter<int, void (*)(int)>(array, 5, test_print_int);
	std::cout << std::endl;
	iter<const int, void (*)(const int)>(carray, 5, test_print_int);
	std::cout << std::endl;

	return (0);
}
