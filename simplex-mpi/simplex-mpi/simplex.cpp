#include "pch.h"
#include "simplex.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <map>

simplex::simplex() : objective({6,5},2)
{
	constraints.push_back(constraint({ 1,1 }, 2, 0, 5));
	constraints.push_back(constraint({ 3,2 }, 2, 1, 12));
	variable_cnt = 2;
	constraint_cnt = constraints.size();
}


simplex::~simplex()
{
}

std::pair<int,double> simplex::get_max_increase_for_variable(int variable)
{
	std::vector<double> max_increase;
	max_increase.reserve(constraint_cnt);
	for (auto const& v : constraints)
	{
		max_increase.push_back(v.get_max_increase(variable));
	}
	auto x = std::min_element(max_increase.begin(), max_increase.end());
	return std::pair<int, double>(x - max_increase.begin(), *x);
}

std::pair<int, int> simplex::get_pivot_element()
{
	std::vector<std::pair<int, double>> list;
	for (size_t i = 0; i < variable_cnt; i++)
	{
		auto max = get_max_increase_for_variable(i);
		max.second *= -objective.variables.at(i);
		list.push_back(max);
	}
	std::pair<int, int> pivot_element;
	pivot_element.first = 0;
	pivot_element.second = list.at(0).first;
	double max_value = list.at(0).second;
	for (size_t i = 1; i < list.size(); i++)
	{
		if (list.at(i).second > max_value)
		{
			pivot_element.first = i;
			pivot_element.second = list.at(i).first;
		}
	}
	return pivot_element;
}

void simplex::exchange(std::pair<int,int> pivot)
{
	constraint const& pivot_row = constraints.at(pivot.second);
	objective.exchange(pivot_row, pivot.first);
	for (size_t i = 0; i < constraints.size(); i++)
	{
		if (i == pivot.second)
			continue;
		constraints.at(i).exchange(pivot_row, pivot.first);
	}
}

void simplex::solve()
{
	while (!objective.optimal_solution_reached())
	{
		std::pair<int, int> pivot = get_pivot_element();
		exchange(pivot);
	}
	auto res = get_results();
	for (auto const& x : res)
	{
		std::cout << x << " ";
	}
	std::cout << "= " << abs(objective.rs);
	std::cout << std::endl;
}

std::vector<double> simplex::get_results()
{
	std::vector<double> result(variable_cnt);
	for (auto const& x : constraints)
	{
		for (size_t i = 0; i < x.variables.size(); i++)
		{
			if (x.variables.at(i) > 0)
			{
				result.at(i) = x.rs / x.variables.at(i);
			}
		}
	}
	return result;
}

void simplex::parse_file(std::string filename)
{
	size_t pos_beg = filename.find_last_of("/KI_");
	if (pos_beg == std::string::npos)
	{
		pos_beg = filename.find_last_of("\\KI_");
	}
	size_t pos_end = filename.find_last_of(".txt");
	int decision_cnt = std::stoi(filename.substr(pos_beg+1,pos_end-pos_beg-4));

	std::fstream file(filename, std::ios::in);
	std::string tmp;
	while (std::getline(file,tmp))
	{
		if (tmp.find("//") != std::string::npos)
			continue;
		if (tmp.length() == 0)
			continue;
		if (tmp.find("max:") != std::string::npos || tmp.find("min:") != std::string::npos)
		{

		}

	}
	int x = 0;
}
