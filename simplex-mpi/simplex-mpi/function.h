#pragma once
#include <vector>
class function
{
public:
	function(std::vector<double> var, int slack_amount);
	virtual ~function();
	void get_base_solution();
	std::vector<double> variables;
	std::vector<double> slack;
	double rs;
};

