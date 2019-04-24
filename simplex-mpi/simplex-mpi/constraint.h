#pragma once
#include <vector>
class constraint
{
public:
	constraint(std::vector<double> var, int slack_amount, int slack_position, double rs_value);
	virtual ~constraint();
	double get_max_increase(int variable) const;
	std::vector<double> variables;
	std::vector<double> slack;
	double rs;
};

