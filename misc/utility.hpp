#pragma once
#include <iostream>

template<typename Container>
inline std::ostream& print(Container const& seq)
{
	std::cout << "{ ";
	for (auto const& elem : seq)
		std::cout << elem << " ";
	std::cout << "}";
	
	return std::cout; 
}