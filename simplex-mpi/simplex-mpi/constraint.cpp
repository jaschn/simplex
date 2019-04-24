#include "pch.h"
#include "constraint.h"


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
