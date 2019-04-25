#pragma once
#include <vector>
#include "constraint.h"
#include "function.h"
class simplex
{
public:
	simplex();
	virtual ~simplex();
	std::pair<int,double> get_max_increase_for_variable(int variable);
	std::pair<int, int> get_pivot_element();
	void exchange(std::pair<int,int> pivot);
	void solve();
	std::vector<double> get_results();
private:
	std::vector<constraint> constraints;
	function objective;
	int variable_cnt;
	int constraint_cnt;
};

