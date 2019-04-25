#pragma once
#include <vector>
#include "constraint.h"
class function
{
public:
	function(std::vector<double> var, int slack_amount);
	virtual ~function();
	void get_base_solution();
	void exchange(constraint const& pivot_row, int pivot_column);
	bool optimal_solution_reached();
	std::vector<double> variables;
	std::vector<double> slack;
	double rs;
};

