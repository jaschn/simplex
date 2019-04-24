#include "pch.h"
#include "function.h"
#include <algorithm>


function::function(std::vector<double> var, int slack_amount): variables(var)
{

}


function::~function()
{
}

void function::get_base_solution()
{
	if (*std::min_element(variables.begin(), variables.end()) >= 0)
	{
		rs = 0;
		return;
	}
}
