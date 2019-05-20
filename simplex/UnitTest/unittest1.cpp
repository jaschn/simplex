#include "stdafx.h"
#include "CppUnitTest.h"
#include "../simplex/simplex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(simplex_test)
	{
	public:
		TEST_METHOD(KI_5)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_5.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(3.57142857142857), round(a_res));
		}

		TEST_METHOD(KI_8)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_8.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(14.5714285714286), round(a_res));
		}

		TEST_METHOD(KI_9)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_9.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(21.948275862069), round(a_res));
		}

		TEST_METHOD(KI_10)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_10.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(29.8095238095238), round(a_res));
		}

		TEST_METHOD(KI_15)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_15.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(36.6352941176471), round(a_res));
		}

		TEST_METHOD(KI_20)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_20.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(60.9032258064516), round(a_res));
		}

		TEST_METHOD(KI_30)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_30.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(261.768774703557), round(a_res));
		}

		double tolerance = 0.000000000001;

		TEST_METHOD(KI_5_tolerance)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_5.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(3.57142857142857 - a_res) < tolerance);
		}

		TEST_METHOD(KI_8_tolerance)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_8.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(14.5714285714286 - a_res) < tolerance);
		}

		TEST_METHOD(KI_9_tolerance)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_9.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(21.948275862069 - a_res) < tolerance);
		}

		TEST_METHOD(KI_10_tolerance)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_10.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(29.8095238095238 - a_res) < tolerance);
		}

		TEST_METHOD(KI_15_tolerance)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_15.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(36.6352941176471 - a_res) < tolerance);
		}

		TEST_METHOD(KI_20_tolerance)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_20.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(60.9032258064516 - a_res) < tolerance);
		}

		TEST_METHOD(KI_30_tolerance)
		{
			simplex a;
			a.parse_file("C:/Users/Jakob/Documents/GitHub/simplex/KI_30.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(261.768774703557 - a_res) < tolerance);
		}
	};
}