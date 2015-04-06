#pragma once


namespace clrs
{
	namespace ch02
	{
		template<typename Container>
		Container merge_and_count_invertions(Container lhs, Container rhs, typename Container::size_type & count)
		{
			Container ret;
			auto l = lhs.cbegin();
			auto r = rhs.cbegin();

			//compare and copy, until either one exausted
			while (l != lhs.cend() && r != rhs.cend())
				ret.push_back(*(*r < *l ? (count += lhs.cend() - l, r) : l)++);


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
		Container find_inversions_by_mergesort(Container const& seq, typename Container::size_type & count)
		{
			if (seq.size() > 1)
			{
				auto mid = seq.cbegin() + seq.size() / 2;
				auto lhs = find_inversions_by_mergesort(Container(seq.cbegin(), mid), count);
				auto rhs = find_inversions_by_mergesort(Container(mid, seq.cend()), count);
				return merge_and_count_invertions(lhs, rhs, count);
			}
			return seq;
		}
	}
}