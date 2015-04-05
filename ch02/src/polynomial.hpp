#pragma once

namespace clrs
{
	namespace ch02
	{
		template<typename Sequence>
		typename Sequence::value_type naive_evaluate(Sequence const& seq, typename Sequence::value_type x)
		{
			using Value = typename Sequence::value_type;
			
			auto y = Value(0);
			for (int i = 0; i != seq.size(); ++i)
			{
				auto x_part = Value(1);
				for (auto k = i; k != 0; --k)
					x_part *= x;
				y += x_part * seq[i];
			}

			return y;
		}

		template<typename Sequence>
		typename Sequence::value_type horner_evaluate(Sequence const& seq, typename Sequence::value_type x)
		{
			using Value = typename Sequence::value_type;

			auto y = Value(0);
			for (auto coefficient = seq.crbegin(); coefficient != seq.crend(); ++coefficient)
				y = *coefficient + x*y;
			return y;
		}
	}
}