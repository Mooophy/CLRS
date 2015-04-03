#pragma once 

namespace clrs
{
	namespace ch02
	{
		template<typename Container>
		Container add_binary_numbers(Container const& lhs, Container const& rhs)
		{
			Container sum(lhs.size() + 1);
			auto l = lhs.crbegin();
			auto r = rhs.crbegin();
			typename Container::value_type carry = 0;
			for (auto curr = sum.rbegin(); curr != sum.rend() - 1; ++curr)
			{
				unsigned bit_sum = *l++ + *r++ + carry;
				*curr = bit_sum % 2;
				carry = bit_sum / 2;
			}
			sum[0] = carry;

			return sum;
		}
	}
}