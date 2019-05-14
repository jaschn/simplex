#include "pch.h"
#include "function.h"
#include <algorithm>

function::function()
{
}

function::~function()
{

}

void function::set_function(std::string const & fun, int decision_cnt)
{
	int x;
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
