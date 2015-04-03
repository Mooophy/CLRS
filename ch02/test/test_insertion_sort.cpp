#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/insertion_sort.hpp"
#include <vector>
#include <deque>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test_insertion_sort)
	{
	public:

		TEST_METHOD(insertion_sort_case1)
		{
			std::vector<int> sample = { 1, 5, 2, 1, 6 };
			std::vector<int> expect = { 1, 1, 2, 5, 6 };
			clrs::ch02::insertion_sort(sample);
			Assert::IsTrue(sample == expect);
		}

		TEST_METHOD(insertion_sort_case2)
		{
			std::vector<int> sample = { 5 };
			std::vector<int> expect = { 5 };
			clrs::ch02::insertion_sort(sample);
			Assert::IsTrue(sample == expect);
		}

		TEST_METHOD(insertion_sort_case3)
		{
			std::vector<int> sample = {};
			std::vector<int> expect = {};
			clrs::ch02::insertion_sort(sample);
			Assert::IsTrue(sample == expect);
		}

		TEST_METHOD(insertion_sort_case4)
		{
			std::deque<int> sample = { 1, 5, 2, 1, 6 };
			std::deque<int> expect = { 1, 1, 2, 5, 6 };
			clrs::ch02::insertion_sort(sample);
			Assert::IsTrue(sample == expect);
		}

		TEST_METHOD(insertion_sort_case5_reverse)
		{
			std::deque<int> sample = { 1, 5, 2, 1, 6 };
			std::deque<int> expect = { 6, 5, 2, 1, 1 };
			clrs::ch02::insertion_sort<std::deque<int>, std::less<int>>(sample);
			Assert::IsTrue(sample == expect);
		}

		TEST_METHOD(insertion_sort_case6_reverse)
		{
			std::vector<int> sample = {};
			std::vector<int> expect = {};
			clrs::ch02::insertion_sort<std::vector<int>, std::less<int>>(sample);
			Assert::IsTrue(sample == expect);
		}

	};
}