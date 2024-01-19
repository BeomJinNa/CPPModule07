#pragma once
#ifndef ITER_HPP
# define ITER_HPP

# include <cstddef>

template <typename T, typename F>
void	iter(T* address, std::size_t size, F function)
{
	for (size_t index = 0; index < size; ++index)
		function(address[index]);
}
#endif
