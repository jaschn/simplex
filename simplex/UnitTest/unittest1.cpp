#include "stdafx.h"
#include "CppUnitTest.h"
#include "../simplex/simplex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(simplex_test)
	{
	public:
		double tolerance = 0.00000005;
		TEST_METHOD(KI_5)
		{
			simplex a;
			a.parse_file("D:/Jakob/Dokumente/GitHub/simplex/KI_5.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(3.57142857142857-a_res) < tolerance);
		}

		TEST_METHOD(KI_8)
		{
			simplex a;
			a.parse_file("D:/Jakob/Dokumente/GitHub/simplex/KI_8.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(14.5714285714286 - a_res) < tolerance);
		}

		TEST_METHOD(KI_9)
		{
			simplex a;
			a.parse_file("D:/Jakob/Dokumente/GitHub/simplex/KI_9.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(21.948275862069 - a_res) < tolerance);
		}

		TEST_METHOD(KI_10)
		{
			simplex a;
			a.parse_file("D:/Jakob/Dokumente/GitHub/simplex/KI_10.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(29.8095238095238 - a_res) < tolerance);
		}

		TEST_METHOD(KI_15)
		{
			simplex a;
			a.parse_file("D:/Jakob/Dokumente/GitHub/simplex/KI_15.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(36.6352941176471 - a_res) < tolerance);
		}

		TEST_METHOD(KI_20)
		{
			simplex a;
			a.parse_file("D:/Jakob/Dokumente/GitHub/simplex/KI_20.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(60.9032258064516 - a_res) < tolerance);
		}

		TEST_METHOD(KI_30)
		{
			simplex a;
			a.parse_file("D:/Jakob/Dokumente/GitHub/simplex/KI_30.txt");
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(261.768774703557 - a_res) < tolerance);
		}
	};
}