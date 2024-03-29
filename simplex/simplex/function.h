#pragma once
#include <vector>
#include "constraint.h"
class function
{
public:
	function();
	virtual ~function();
	void set_function(std::string fun, int decision_cnt);
	void set_slack_cnt(int slack_amount);
	void exchange(constraint const& pivot_row, int pivot_column);
	bool optimal_solution_reached();
	void set_negative();
	std::vector<double> variables;
	std::vector<double> slack;
	double rs;
};

