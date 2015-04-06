#include "stdafx.h"
#include "CppUnitTest.h"
#include "../src/polynomial.hpp"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test_polynomial)
	{
	public:
		
		TEST_METHOD(naive_evaluate_case1)
		{
			auto sample = std::vector < int > { 1 }; //y = 1
			auto x = 2;
			auto expect = 1;
			auto actual = clrs::ch02::naive_evaluate(sample, x);

			Assert::AreEqual(actual, expect);
		}

		TEST_METHOD(naive_evaluate_case2)
		{
			auto sample = std::vector < int > { 1, 2 }; // y = 1 + 2x
			auto x = 2;
			auto expect = 5;
			auto actual = clrs::ch02::naive_evaluate(sample, x);

			Assert::AreEqual(actual, expect);
		}

		TEST_METHOD(naive_evaluate_case3)
		{
			auto sample = std::vector < int > { 5, 2, 0, 7};	// y = 5 + 2x + 0x^2 + 7x^3
			auto x = 2;											//	 = 5 + 4  + 0    + 56 = 65					
			auto expect = 65;
			auto actual = clrs::ch02::naive_evaluate(sample, x);

			Assert::AreEqual(expect, actual);
		}

		TEST_METHOD(horner_evaluate_case1)
		{
			auto sample = std::vector < int > { 1 }; //y = 1
			auto x = 2;
			auto expect = 1;
			auto actual = clrs::ch02::horner_evaluate(sample, x);

			Assert::AreEqual(actual, expect);
		}

		TEST_METHOD(horner_evaluate_case2)
		{
			auto sample = std::vector < int > { 1, 2 }; // y = 1 + 2x
			auto x = 2;
			auto expect = 5;
			auto actual = clrs::ch02::horner_evaluate(sample, x);

			Assert::AreEqual(actual, expect);
		}

		TEST_METHOD(horner_evaluate_case3)
		{
			auto sample = std::vector < int > { 5, 2, 0, 7};	// y = 5 + 2x + 0x^2 + 7x^3
			auto x = 2;											//	 = 5 + 4  + 0    + 56 = 65					
			auto expect = 65;
			auto actual = clrs::ch02::horner_evaluate(sample, x);

			Assert::AreEqual(expect, actual);
		}

	};
}