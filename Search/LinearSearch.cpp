#include <iostream>
#include <vector>

template<class Collection>
using ValueType = typename Collection::value_type;

template<class Collection>
using SizeType = typename Collection::size_type;

template<class Collection>
int linearSearchNonRecursive(const Collection& col, const ValueType<Collection>& val) noexcept
{
	for(SizeType<Collection> i = 0u; i < col.size(); i++)
	{
		if (col[i] == val)
			return static_cast<int>(i);
	}
	return -1;
}

template<class Collection>
int linearSearchRecursive(const Collection& collection,
						  const ValueType<Collection>& value,
						  const SizeType<Collection> index = 0u) noexcept
{
	if(index == collection.size())
	{
		return -1;
	}
	else if (collection[index] == value)
	{
		return index;
	}
	else
	{
		return linearSearchRecursive(collection, value, index + 1);
	}
}

int main()
{
	const std::vector<int> vector = { 2,3,7,17,27,44,57,61,87,91 };

	std::cout << "Index: " << linearSearchNonRecursive(vector, 87) << std::endl;
	std::cout << "Index: " << linearSearchRecursive(vector, 17) << std::endl;
	
	return 0;
}