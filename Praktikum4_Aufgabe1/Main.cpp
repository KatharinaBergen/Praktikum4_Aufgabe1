/*
Author: Kat Bergen
v01 19.06.2020

Implement a vector<int> with as many random integers as user defines and sort it using 2 versions of the insertion sort algorithm. Measure runtime. 

PAD1 P4A1
*/

#include "Functions.h"
#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

int main() try
{ 
    //Step 1 setting up the vector to be sorted

    std::vector<int> vec{}; //vector to hold randomly generated elements to be sorted
    unsigned int count{}; //amount of elements in vector
    int lowerBound{}; //lower boundary for randomly generated items in vector
    int upperBound{}; //upper boundary for randomly generated items in vector
    userInput(count, lowerBound, upperBound); //redefine variable values
    fillVector(vec, count, lowerBound, upperBound); //fill vector with random numbers
       
    //Intermediate Step 0 start tracking time it takes to run code
    high_resolution_clock::time_point my_end{};
    high_resolution_clock::time_point my_start{
    high_resolution_clock::now() // static time_point now() noexcept
    };

    insSort_v0(vec, 0, vec.size()); //Step 2 sort vector VERSION 0
    //insSort_v1(vec, 0, vec.size()); //Step 2 sort vector VERSION 1

    //Intermediate Step 1 end tracking time and output result
    my_end = high_resolution_clock::now();
    milliseconds ms{ duration_cast<milliseconds>(my_end - my_start) };
    std::cout << ms.count() << " Millisekunden";

    isSorted_(vec); //Step 3 check if sorted correctly
    output(vec); //Step 4 print vector if user indicated he wants to see it


    return 0;

}
catch (std::runtime_error e)
{
    std::cerr << e.what();
}
catch (...)
{
    std::cerr << "unknown error";
}