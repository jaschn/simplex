#include "pch.h"
#include "constraint.h"
#include <regex>

constraint::constraint()
{
}

constraint::~constraint()
{
}

void constraint::set_constraint(std::string const & eq, int decision_cnt)
{
}

void constraint::set_slack(int slack_amount, int slack_position)
{
	slack.clear();
	for (size_t i = 0; i < slack_amount; i++)
	{
		slack.push_back(0);
	}
	slack.at(slack_position) = 1;
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
