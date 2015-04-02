#pragma once 
#include <functional>

namespace clrs
{
	namespace ch02
	{
		template<typename Container, typename CompareFunc = std::greater<typename Container::value_type>>
		void insertion_sort(Container& seq)
		{
			if (seq.size() <= 1)	return;

			CompareFunc compare;
			for (int i = 1; i != seq.size(); ++i)
			{
				auto key = seq[i];
				auto j = i - 1;
				for (; j >= 0 && compare(seq[j], key); --j)	seq[j + 1] = seq[j];
				seq[j + 1] = key;
			}
		}
	}
}