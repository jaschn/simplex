#include "stdafx.h"
#include "CppUnitTest.h"
#include "../simplex/simplex.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#define STRINGIFY(x) #x
#define EXPAND(x) STRINGIFY(x)

namespace UnitTest
{		
	TEST_CLASS(simplex_test)
	{
	public:
		TEST_METHOD(KI_5)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_5.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(3.57142857142857), round(a_res));
		}

		TEST_METHOD(KI_8)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_8.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(14.5714285714286), round(a_res));
		}

		TEST_METHOD(KI_9)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_9.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(21.948275862069), round(a_res));
		}

		TEST_METHOD(KI_10)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_10.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(29.8095238095238), round(a_res));
		}

		TEST_METHOD(KI_15)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_15.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(36.6352941176471), round(a_res));
		}

		TEST_METHOD(KI_20)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_20.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(60.9032258064516), round(a_res));
		}

		TEST_METHOD(KI_30)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_30.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::AreEqual(round(261.768774703557), round(a_res));
		}

		double tolerance = 0.000000000001;

		TEST_METHOD(KI_5_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_5.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(3.57142857142857 - a_res) < tolerance);
		}

		TEST_METHOD(KI_8_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_8.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(14.5714285714286 - a_res) < tolerance);
		}

		TEST_METHOD(KI_9_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_9.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(21.948275862069 - a_res) < tolerance);
		}

		TEST_METHOD(KI_10_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_10.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(29.8095238095238 - a_res) < tolerance);
		}

		TEST_METHOD(KI_15_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_15.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(36.6352941176471 - a_res) < tolerance);
		}

		TEST_METHOD(KI_20_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_20.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(60.9032258064516 - a_res) < tolerance);
		}

		TEST_METHOD(KI_30_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_30.txt";
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_results();
			Assert::IsTrue(abs(261.768774703557 - a_res) < tolerance);
		}
	};
}