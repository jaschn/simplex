#include "pch.h"
#include "function.h"
#include <algorithm>


function::function(std::vector<double> var, int slack_amount): variables(var),slack(slack_amount)
{

}


function::~function()
{
}

void function::get_base_solution()
{
	if (*std::min_element(variables.begin(), variables.end()) >= 0)
	{
		rs = 0;
		return;
	}
}

void function::exchange(constraint const& pivot_row, int pivot_column)
{
	double factor = variables.at(pivot_column);
	variables.at(pivot_column) = 0;
	rs -= factor * pivot_row.rs;
	for (size_t i = 0; i < variables.size(); i++)
	{
		if (i == pivot_column)
			continue;
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
		if (x > 0)
			return false;
	}
	for (auto const& x : slack)
	{
		if (x > 0)
			return false;
	}
	return true;
}
