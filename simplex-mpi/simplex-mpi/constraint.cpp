#include "pch.h"
#include "constraint.h"
#include <regex>

constraint::constraint()
{
}

constraint::~constraint()
{
}

void constraint::set_constraint(std::string eq, int decision_cnt)
{
	variables.reserve(decision_cnt);
	eq.erase(0, 1);
	while (variables.size()<decision_cnt)
	{
		bool is_negative;
		if (eq.at(0) == '-')
			is_negative = true;
		else
			is_negative = false;
		eq.erase(0, 2);
		size_t factor_len = eq.find_first_of('*');
		double factor = std::stoi(eq.substr(0, factor_len));
		if (is_negative)
			factor = -factor;
		variables.push_back(factor);
		size_t next = eq.find_first_of(' ');
		eq.erase(0, next + 1);
	}
	size_t next = eq.find_first_of(' ');
	size_t end = eq.find_first_of(';');
	rs = std::stoi(eq.substr(next+1, end));
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
	double factor = variables.at(pivot_column)/pivot_row.variables.at(pivot_column);
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
