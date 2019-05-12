#include "pch.h"
#include "constraint.h"
#include <regex>

constraint::constraint(std::vector<double> var, int slack_amount, int slack_position, double rs_value): variables(var), rs(rs_value), slack(slack_amount)
{
	slack.at(slack_position) = 1;
}

constraint::~constraint()
{
}

double constraint::get_max_increase(int variable) const
{
	return rs/variables.at(variable);
}

void constraint::exchange(constraint const& pivot_row, int pivot_column)
{
	double factor = variables.at(pivot_column);
	rs -= factor*pivot_row.rs;
	for (size_t i = 0; i < variables.size(); i++)
	{
		variables.at(i) -= factor*pivot_row.variables.at(i);
	}
	for (size_t i = 0; i < slack.size(); i++)
	{
		slack.at(i) -= factor * pivot_row.slack.at(i);
	}
}
