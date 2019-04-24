#include "pch.h"
#include "simplex.h"
#include <algorithm>

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
		list.push_back(get_max_increase_for_variable(i));
	}
	std::pair<int, int> pivot_element;
	double max_value;
	pivot_element.first = 0;
	pivot_element.second = 0;
	max_value = list.at(0).second;
	for (size_t i = 0; i < list.size(); i++)
	{
		if (list.at(i).second > max_value)
		{
			pivot_element.first = i;
			pivot_element.second = list.at(i).first;
		}
	}
	return pivot_element;
}
