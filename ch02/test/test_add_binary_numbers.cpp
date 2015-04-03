#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/add_binary_numbers.hpp"

#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test_add_binary_numbers)
	{
	public:
		
		TEST_METHOD(test_add_binary_numbers_case1)
		{
			std::vector<char> lhs = { 1, 1 };
			std::vector<char> rhs = { 0, 1 };
			auto actual = clrs::ch02::add_binary_numbers(lhs, rhs);
			std::vector<char> expect = { 1, 0, 0 };
			Assert::IsTrue(actual == expect);
		}

		TEST_METHOD(test_add_binary_numbers_case2)
		{
			std::vector<char> lhs = { 0 };
			std::vector<char> rhs = { 0 };
			auto actual = clrs::ch02::add_binary_numbers(lhs, rhs);
			std::vector<char> expect = { 0, 0 };
			Assert::IsTrue(actual == expect);
		}

		TEST_METHOD(test_add_binary_numbers_case3)
		{
			std::vector<char> lhs = { 1, 1, 1, 1 };
			std::vector<char> rhs = { 1, 1, 1, 1 };
			auto actual = clrs::ch02::add_binary_numbers(lhs, rhs);
			std::vector<char> expect = { 1, 1, 1, 1, 0 };
			Assert::IsTrue(actual == expect);
		}
	};
}