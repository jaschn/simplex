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

		double tolerance = 0.0000000000009;

		TEST_METHOD(KI_5_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_5.txt";
			std::vector<double> ref = { 2.61904761904762, 0, 0, 0, 0.476190476190476};
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_result();
			Assert::IsTrue(abs(3.57142857142857 - a_res) < tolerance);
			auto results = a.get_result_values();
			for (int i = 0; i < results.size(); i++)
			{
				Assert::IsTrue(abs(ref.at(i) - results.at(i)) < tolerance);
			}
		}

		TEST_METHOD(KI_8_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_8.txt";
			std::vector<double> ref = {0, 0, 0, 0, 7.28571428571429, 0, 0, 0};
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_result();
			Assert::IsTrue(abs(14.5714285714286 - a_res) < tolerance);
			auto results = a.get_result_values();
			for (int i = 0; i < results.size(); i++)
			{
				Assert::IsTrue(abs(ref.at(i) - results.at(i)) < tolerance);
			}
		}

		TEST_METHOD(KI_9_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_9.txt";
			std::vector<double> ref = {0, 0, 5.55172413793104, 0, 0, 0, 0, 0, 5.29310344827586};
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_result();
			Assert::IsTrue(abs(21.948275862069 - a_res) < tolerance);
			auto results = a.get_result_values();
			for (int i = 0; i < results.size(); i++)
			{
				Assert::IsTrue(abs(ref.at(i) - results.at(i)) < tolerance);
			}
		}

		TEST_METHOD(KI_10_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_10.txt";
			std::vector<double> ref = {0,0,0,0.857142857142856,0,0,0,14.047619047619,0,0 };
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_result();
			Assert::IsTrue(abs(29.8095238095238 - a_res) < tolerance);
			auto results = a.get_result_values();
			for (int i = 0; i < results.size(); i++)
			{
				Assert::IsTrue(abs(ref.at(i) - results.at(i)) < tolerance);
			}
		}

		TEST_METHOD(KI_15_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_15.txt";
			std::vector<double> ref = {12.7764705882353,0,0,0,0,0,0,0,0,0,0,0,11.9294117647059,0,0 };
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_result();
			Assert::IsTrue(abs(36.6352941176471 - a_res) < tolerance);
			auto results = a.get_result_values();
			for (int i = 0; i < results.size(); i++)
			{
				Assert::IsTrue(abs(ref.at(i) - results.at(i)) < tolerance);
			}
		}

		TEST_METHOD(KI_20_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_20.txt";
			std::vector<double> ref = {0,0,13.5645161290323,16.8870967741935,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_result();
			Assert::IsTrue(abs(60.9032258064516 - a_res) < tolerance);
			auto results = a.get_result_values();
			for (int i = 0; i < results.size(); i++)
			{
				Assert::IsTrue(abs(ref.at(i) - results.at(i)) < tolerance);
			}
		}

		TEST_METHOD(KI_30_tolerance)
		{
			std::string s = EXPAND(UNITTESTPRJ);
			s.erase(0, 1);
			s.erase(s.size() - 2);
			s += "..\\..\\KI_30.txt";
			std::vector<double> ref = {0,25.8001599849426,0,0,0,0,10.1892841458059,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2.50287816048685,0,0,49.7368404542318,0,0};
			simplex a;
			a.parse_file(s);
			a.solve();
			double a_res = a.get_result();
			Assert::IsTrue(abs(261.768774703557 - a_res) < tolerance);
			auto results = a.get_result_values();
			for (int i = 0; i < results.size(); i++)
			{
				Assert::IsTrue(abs(ref.at(i) - results.at(i)) < tolerance);
			}
		}
	};
}