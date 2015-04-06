#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/selection_sort.hpp"
#include <vector>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test_selection_sort)
	{
	public:
		
		TEST_METHOD(test_selection_sort_case1)
		{
			std::vector<int> sample = { 1, 5, 2, 1, 6 };
			std::vector<int> expect = { 1, 1, 2, 5, 6 };
			Assert::IsTrue(clrs::ch02::selection_sort(sample) == expect);
		}

		TEST_METHOD(test_selection_sort_case2)
		{
			std::vector<int> sample = { 6 };
			std::vector<int> expect = { 6 };
			Assert::IsTrue(clrs::ch02::selection_sort(sample) == expect);
		}

		TEST_METHOD(test_selection_sort_case3_string)
		{
			std::vector<std::string> sample = { "a", "2", "z", "bb", "0" };
			std::vector<std::string> expect = { "0", "2", "a", "bb", "z" };
			Assert::IsTrue(clrs::ch02::selection_sort(sample) == expect);
		}
	};
}