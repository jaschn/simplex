#pragma once
#include <vector>
#include "constraint.h"
#include "function.h"
class simplex
{
public:
	simplex();
	virtual ~simplex();
	void transpose();
	std::pair<int, int> get_pivot_element();
	void exchange(std::pair<int,int> pivot);
	void solve();
	double get_result();
	bool parse_file(std::string filename);
	std::vector<double> get_result_values();
	
private:
	std::vector<constraint> constraints;
	function objective;
	int variable_cnt;
	int constraint_cnt;
	bool max_function;
};

