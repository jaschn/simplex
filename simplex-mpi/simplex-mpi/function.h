#pragma once
#include <vector>
#include "constraint.h"
class function
{
public:
	function(std::vector<double> var, int slack_amount);
	function(std::string const& fun, int decision_cnt);
	virtual ~function();
	void exchange(constraint const& pivot_row, int pivot_column);
	bool optimal_solution_reached();
	std::vector<double> variables;
	std::vector<double> slack;
	double rs;
};

