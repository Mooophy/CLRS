#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/merge_sort.hpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test_merge_sort)
	{
	public:
		
		TEST_METHOD(test_merge_case1)
		{
			auto ret = clrs::ch02::merge(std::vector<int>(), std::vector<int>());
			Assert::IsTrue(ret == std::vector<int>());
		}

		TEST_METHOD(test_merge_case2)
		{
			auto ret = clrs::ch02::merge(std::vector < int > {1}, std::vector < int > {1});
			Assert::IsTrue(ret == std::vector < int > {1,1});
		}

		TEST_METHOD(test_merge_case3)
		{
			auto ret = clrs::ch02::merge(std::vector < int > {2, 3}, std::vector < int > {1, 4});
			Assert::IsTrue(ret == std::vector < int > {1, 2, 3, 4});
		}

		TEST_METHOD(test_merge_case4)
		{
			auto ret = clrs::ch02::merge(std::vector < int > {1}, std::vector < int > {5, 6, 7, 8});
			Assert::IsTrue(ret == std::vector < int > {1, 5, 6, 7, 8});
		}

		TEST_METHOD(test_merge_sort_case1)
		{
			auto sample = std::vector < int > {2, 1};
			auto ret = clrs::ch02::merge_sort(sample);
			Assert::IsTrue(ret == std::vector < int > {1, 2});
		}

		TEST_METHOD(test_merge_sort_case2)
		{
			auto sample = std::vector < int > {};
			auto ret = clrs::ch02::merge_sort(sample);
			Assert::IsTrue(ret == std::vector < int > {});
		}

		TEST_METHOD(test_merge_sort_case3)
		{
			auto sample = std::vector < int > { 1, 5, 2, 1, 6 };
			auto ret = clrs::ch02::merge_sort(sample);
			Assert::IsTrue(ret == std::vector < int > { 1, 1, 2, 5, 6 });
		}

	};
}