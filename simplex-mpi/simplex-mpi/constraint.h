#pragma once
#include <vector>
class constraint
{
public:
	constraint();
	virtual ~constraint();
	void set_constraint(std::string const& eq, int decision_cnt);
	void set_slack(int slack_amount, int slack_position);
	double get_max_increase(int variable) const;
	void exchange(constraint const& pivot_row, int pivot_column);
	std::vector<double> variables;
	std::vector<double> slack;
	double rs;
};

