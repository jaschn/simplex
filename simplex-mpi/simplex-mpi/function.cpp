#include "pch.h"
#include "function.h"
#include <algorithm>
#include <string>

function::function()
{
}

function::~function()
{

}

void function::set_function(std::string fun, int decision_cnt)
{
	variables.reserve(decision_cnt);
	fun.erase(0, 5);
	while (variables.size() < decision_cnt)
	{
		bool is_negative;
		if (fun.at(0) == '-')
			is_negative = true;
		else
			is_negative = false;
		fun.erase(0, 2);
		size_t factor_len = fun.find_first_of('*');
		double factor = std::stoi(fun.substr(0, factor_len));
		if (is_negative)
			factor = -factor;
		variables.push_back(factor);
		size_t next = fun.find_first_of(' ');
		if (next == std::string::npos)
			break;
		fun.erase(0, next + 1);
	}
}

void function::set_slack_cnt(int slack_amount)
{
	slack.clear();
	for (size_t i = 0; i < slack_amount; i++)
	{
		slack.push_back(0);
	}
}

void function::exchange(constraint const& pivot_row, int pivot_column)
{
	double factor = variables.at(pivot_column);
	rs -= factor * pivot_row.rs;
	for (size_t i = 0; i < variables.size(); i++)
	{
		variables.at(i) -= factor * pivot_row.variables.at(i);
	}
	for (size_t i = 0; i < slack.size(); i++)
	{
		slack.at(i) -= factor * pivot_row.slack.at(i);
	}
}

bool function::optimal_solution_reached()
{
	for (auto const& x : variables)
	{
		if (x < 0)
			return false;
	}
	return true;
}
