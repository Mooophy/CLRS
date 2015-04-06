#pragma once

namespace clrs 
{
	namespace ch02
	{
		template<typename Container>
		Container merge(Container lhs, Container rhs)
		{
			Container ret;
			auto l = lhs.cbegin();
			auto r = rhs.cbegin();
			
			//compare and copy, until either one exausted
			while (l != lhs.cend() && r != rhs.cend())
				ret.push_back(*(*r < *l ? r : l)++);

			//copy the rest
			if (l == lhs.cend())
				while (r != rhs.cend())
					ret.push_back(*r++);
			else
				while (l != lhs.cend())
					ret.push_back(*l++);

			return ret;
		}

		template<typename Container>
		Container merge_sort(Container const& seq)
		{
			if (seq.size() > 1)
			{
				auto mid = seq.cbegin() + seq.size() / 2;
				auto lhs = merge_sort(Container(seq.cbegin(), mid));
				auto rhs = merge_sort(Container(mid, seq.cend()));
				return merge(lhs, rhs);
			}
			return seq;
		}
	}
}