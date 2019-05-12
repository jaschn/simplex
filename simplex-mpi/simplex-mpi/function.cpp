#include "pch.h"
#include "function.h"
#include <algorithm>


function::function(std::vector<double> var, int slack_amount): variables(var),slack(slack_amount)
{
	for (int i = 0; i < variables.size(); i++)
	{
		variables.at(i) = -variables.at(i);
	}
}


function::~function()
{

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
