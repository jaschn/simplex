#include "pch.h"
#include "simplex.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <set>

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
		max.second *= objective.variables.at(i);
		list.push_back(max);
	}
	std::pair<int, int> pivot_element;
	double max_value;
	pivot_element.first = 0;
	pivot_element.second = list.at(0).first;;
	max_value = list.at(0).second;
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
	std::fstream file(filename, std::ios::in);
	size_t filesize = file.tellg();
	file.seekg(0, std::ios::beg);
	std::string data;
	data.reserve(filesize);
	std::string tmp;
	while (std::getline(file,tmp))
	{
		if (tmp.length() > 1 && tmp[0] == '/' && tmp[1] == '/')
			continue;
		data.append(tmp);
	}
	std::regex whitespace("(\\s)*");
	data = std::regex_replace(data, whitespace, "");
	std::regex comments("((\/\\*){1}.*?(\\*\/){1})");
	data = std::regex_replace(data, comments, "");

	std::set<std::string> variables;
	std::regex var("[a-zA-Z]+[a-zA-Z0-9]*(?!.*:)");
	std::sregex_iterator it(data.begin(), data.end(),var);
	std::sregex_iterator end;
	while (it != end)
	{
		std::string tmp = (*it)[0];
		variables.insert(tmp);
		it++;
	}

	std::vector<std::string> con;
	std::string obj;
	bool parsing_error = false;
	size_t pos = 0;
	std::string eq;
	while ((pos = data.find(";")) != std::string::npos) {
		eq = data.substr(0, pos);
		if (eq.find(":") != std::string::npos)
		{
			if (obj.empty())
			{
				obj = eq;
			}
			else
			{
				parsing_error = true;
			}
		}
		else
		{
			con.push_back(eq);
		}		
		data.erase(0, pos + 1);
	}
	int x = 0;
}
