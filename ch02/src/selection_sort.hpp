#pragma once
#include <algorithm>

namespace clrs
{
	namespace ch02
	{
		template<typename Container>
		Container selection_sort(Container seq)
		{
			if (seq.size() < 2)	return seq;

			for (int i = 0; i != seq.size() - 1; ++i)
			{
				int index_for_min = i;
				for (int j = i; j != seq.size(); ++j)
					if (seq[index_for_min] > seq[j])	index_for_min = j;
				std::swap(seq[i], seq[index_for_min]);
			}
			return seq;
		}
	}
}