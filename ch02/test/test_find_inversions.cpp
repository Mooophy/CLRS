#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/find_inversions.hpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test_find_inversions)
	{
	public:
		
		TEST_METHOD(merge_and_count_invertions_case1)
		{
			auto lhs = std::vector < int > {9};
			auto rhs = std::vector < int > {0};
			std::size_t count = 0;
			clrs::ch02::merge_and_count_invertions(lhs, rhs, count);
			Assert::AreEqual(1u, count);
		}

		TEST_METHOD(merge_and_count_invertions_case2)
		{
			auto lhs = std::vector < int > {8, 9};
			auto rhs = std::vector < int > {0, 1};
			std::size_t count = 0;
			clrs::ch02::merge_and_count_invertions(lhs, rhs, count);
			Assert::AreEqual(4u, count);
		}

		TEST_METHOD(merge_and_count_invertions_case3)
		{
			auto lhs = std::vector < int > {8, 10};
			auto rhs = std::vector < int > {0, 9};
			std::size_t count = 0;
			clrs::ch02::merge_and_count_invertions(lhs, rhs, count);
			Assert::AreEqual(3u, count);
		}

		TEST_METHOD(find_inversions_by_mergesort_case1)
		{
			auto sample = std::vector < int > {2, 1};
			std::size_t count = 0;
			clrs::ch02::find_inversions_by_mergesort(sample, count);
			Assert::AreEqual(1u, count);
		}

		TEST_METHOD(find_inversions_by_mergesort_case2)
		{
			auto sample = std::vector < int > {};
			std::size_t count = 0;
			clrs::ch02::find_inversions_by_mergesort(sample, count);
			Assert::AreEqual(0u, count);
		}

		TEST_METHOD(find_inversions_by_mergesort_case3)
		{
			auto sample = std::vector < int > {2, 3, 8, 6, 1};
			std::size_t count = 0;
			clrs::ch02::find_inversions_by_mergesort(sample, count);
			Assert::AreEqual(5u, count);
		}

	};
}