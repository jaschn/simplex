#include "pch.h"
#include "simplex.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <map>

simplex::simplex()
{
}


simplex::~simplex()
{

}

void simplex::transpose()
{
	std::vector<constraint> transposed_con;
	function transposed_obj;
	for (size_t i = 0; i < variable_cnt; i++)
	{
		constraint tmp;
		for (auto const& x : constraints)
		{
			tmp.variables.push_back(x.variables.at(i));
		}
		tmp.rs = objective.variables.at(i);
		transposed_con.push_back(tmp);
	}
	for (auto const& x : constraints)
	{
		transposed_obj.variables.push_back(x.rs);
	}
	constraints = transposed_con;
	objective = transposed_obj;
}

std::pair<int, int> simplex::get_pivot_element()
{
	std::pair<int, int> pivot;
	double min_value = DBL_MAX;
	pivot.first = 0;
	for (size_t i = 0; i < variable_cnt; i++)
	{
		if (objective.variables.at(i) < min_value)
		{
			min_value = objective.variables.at(i);
			pivot.first = i;
		}
	}
	for (size_t i = 0; i < constraint_cnt; i++)
	{
		if (objective.slack.at(i) < min_value)
		{
			min_value = objective.slack.at(i);
			pivot.first = i + variable_cnt;
		}
	}
	double max_increase = DBL_MAX;
	pivot.second = 0;
	for (size_t i = 0; i < constraint_cnt; i++)
	{
		double divider = 0;
		if (pivot.first >= variable_cnt)
			divider = constraints.at(i).slack.at(pivot.first - variable_cnt);
		else
			divider = constraints.at(i).variables.at(pivot.first);
		double max_inc_con = constraints.at(i).rs / divider;
		if (max_inc_con > 0 && max_inc_con < max_increase)
		{
			max_increase = max_inc_con;
			pivot.second = i;
		}			
	}
	return pivot;
}

void simplex::exchange(std::pair<int,int> pivot)
{
	constraint& pivot_row = constraints.at(pivot.second);
	pivot_row.reduce(pivot.first);
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
}

double simplex::get_result()
{
	return objective.rs;
}

bool simplex::parse_file(std::string filename)
{
	size_t pos_beg = filename.find_last_of("/KI_");
	if (pos_beg == std::string::npos)
	{
		pos_beg = filename.find_last_of("\\KI_");
	}
	size_t pos_end = filename.find_last_of(".txt");
	variable_cnt = std::stoi(filename.substr(pos_beg+1,pos_end-pos_beg-4));

	std::fstream file(filename, std::ios::in);
	if (!file.is_open())
	{
		std::cout << "can't open file" << std::endl << std::endl;
		return false;
	}
	std::string tmp;
	while (std::getline(file,tmp))
	{		
		if (tmp.length() == 0)
			continue;
		if (tmp.find("//") != std::string::npos)
			continue;
		if (tmp.find("max:") != std::string::npos)
		{
			max_function = true;
			objective.set_function(tmp,variable_cnt);
			continue;
		}
		if (tmp.find("min:") != std::string::npos)
		{
			max_function = false;
			objective.set_function(tmp,variable_cnt);
			continue;
		}
		constraint tmp_const;
		tmp_const.set_constraint(tmp, variable_cnt);
		constraints.push_back(tmp_const);
	}
	if (!max_function)
		transpose();
	constraint_cnt = constraints.size();
	variable_cnt = constraints.at(0).variables.size();
	objective.set_slack_cnt(constraint_cnt);
	for (int i = 0; i < constraint_cnt; i++)
	{
		constraints.at(i).set_slack(constraint_cnt, i);
	}
	objective.set_negative();
	return true;
}

std::vector<double> simplex::get_result_values()
{
	std::vector<double> result(variable_cnt);
	if (max_function)
	{
		for (auto & x : constraints)
		{
			for (int i = 0; i < x.variables.size(); i++)
			{
				if (x.variables.at(i) == 1)
				{
					result.at(i) = x.rs;
				}
			}
		}
	}
	else
	{
		result = objective.slack;
	}
	return result;
}
