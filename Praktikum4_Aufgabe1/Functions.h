/*
Author: Kat Bergen
v01 19.06.2020

header with functions for user input, output and sorting & checking if vector is indeed sorted

PAD1 P4A1
*/


#include <random>
#include <functional>
#include <iostream>
#include "MyError.h"

using std::cout;
using std::cin;
using std::vector;


void userInput(unsigned int&, int&, int&);
void fillVector(vector<int>&, const unsigned int&, const int&, const int&);
void swap_if(int& int1, int& int2);
void swap(int& int1, int& int2);
void insSort_v0(vector<int>&, const unsigned int&, const unsigned int&);
void insSort_v1(vector<int>&, const unsigned int&, const unsigned int&);
void printVector(vector<int>&);
void isSorted_(vector<int>&);
void output(vector<int>&);

