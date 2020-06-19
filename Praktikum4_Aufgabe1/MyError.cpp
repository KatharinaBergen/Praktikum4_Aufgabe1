/*
Author: Kat Bergen
v01 19.06.2020

cpp with error function

PAD1 P4A1
*/

#include <string>
#include <stdexcept>

void error(const std::string& s)
{
	throw std::runtime_error{ s };
}