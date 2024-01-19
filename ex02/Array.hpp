#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstddef>
# include <stdexcept>

template <typename T>
class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array<T>& source);
		Array<T>&		operator=(const Array<T>& source);
		~Array(void);

		T&				operator[](unsigned int index);
		const T&		operator[](unsigned int index) const;
		unsigned int	size(void) const;
	private:
		T*				mArray;
		unsigned int	mSize;
};

template <typename T>
Array<T>::Array(void)
	: mArray(NULL)
	, mSize(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n)
	: mArray(NULL)
	, mSize(n)
{
	if (n != 0)
	{
		mArray = new T[n]();
	}
}

template <typename T>
Array<T>::Array(const Array& source)
	: mArray(NULL)
	, mSize(source.mSize)
{
	if (source.mSize != 0)
	{
		mArray = new T[source.mSize]();
	}

	for (unsigned int i = 0; i < mSize; ++i)
	{
		mArray[i] = source.mArray[i];
	}
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& source)
{
	if (this != &source)
	{
		if (mArray != NULL)
		{
			delete[] mArray;
		}
		mArray = NULL;
		if (source.mSize != 0)
		{
			mArray = new T[source.mSize]();
		}
		mSize = source.mSize;
		for (unsigned int i = 0; i < mSize ; ++i)
		{
			mArray[i] = source.mArray[i];
		}
	}

	return (*this);
}

template <typename T>
Array<T>::~Array(void)
{
	if (mArray != NULL)
	{
		delete[] mArray;
	}
}

template <typename T>
T&	Array<T>::operator[](unsigned int index)
{
	if (index >= mSize)
	{
		throw std::out_of_range("Index out of range");
	}

	return (mArray[index]);
}

template <typename T>
const T&	Array<T>::operator[](unsigned int index) const
{
	if (index >= mSize)
	{
		throw std::out_of_range("Index out of range");
	}

	return (mArray[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (mSize);
}
#endif
