/*
Author: Kat Bergen
v01 19.06.2020

cpp with functions for user input, output and sorting & checking if vector is indeed sorted

PAD1 P4A1
*/

#include <random>
#include <functional>
#include <iostream>
#include "MyError.h"

using std::cout;
using std::cin;
using std::vector;

void userInput(unsigned int& count, int& lowerBound, int& upperBound)
{
    //user input amount of numbers to be added to vector
    cout << "Bitte geben Sie ein, wieviele Zahlen Sie genereieren möchten." << std::endl;
    cin >> count;
    if (!cin) error("count, not a positive number.");

    //user input lower boundary for numbers to be added to vector
    cout << "Bitte geben Sie ein, was die kleinsmögliche Zahl der generierten Zahlen sein soll." << std::endl;
    cin >> lowerBound;
    if (!cin) error("lower bound, not a number.");

    //user input lower boundary for numbers to be added to vector
    cout << "Bitte geben Sie ein, was die kleinsmögliche Zahl der generierten Zahlen sein soll." << std::endl;
    cin >> upperBound;
    if (!cin) error("lower bound, not a number.");
}

void fillVector(vector<int>& vec, const unsigned int& count, const int& lowerBound, const int& upperBound)
{
    std::default_random_engine e{};
    std::uniform_int_distribution<int> distr{ lowerBound, upperBound };
    auto ri = bind(distr, e);

    for (int i{ 0 }; i < count; i++)
    {
        vec.push_back(ri());
    }
}

void swap_if(int& int1, int& int2)
{
    int temp{};

    if (int1 > int2)
    {
        temp = int1;
        int1 = int2;
        int2 = temp;
    }
}

void swap(int& int1, int& int2)
{
    int temp{};
    temp = int1;
    int1 = int2;
    int2 = temp;
}

void insSort_v0(vector<int>& vec, const unsigned int& lowerIndex, const unsigned int& upperIndex)
{
    for (unsigned int i{ lowerIndex + 1U }; i < upperIndex; ++i)
        for (unsigned int j{ i }; lowerIndex < j; --j)
            swap_if(vec.at(j - 1U), vec.at(j));
}

void insSort_v1(vector<int>& vec, const unsigned int& lowerIndex, const unsigned int& upperIndex)
{
    unsigned int j{};
    for (unsigned int i{ lowerIndex + 1U }; i < upperIndex; ++i)
    {
        for (j = i; lowerIndex < j; --j)
        {
            if (vec.at(j - 1U) < vec.at(j)) break;
            swap(vec.at(j - 1U), vec.at(j));
        }
    }
}

void printVector(vector<int>& vec)
{
    for (int i{}; i < vec.size(); i++)
    {
        cout << vec.at(i) << ' ' << std::endl;
    }
}

void isSorted_(vector<int>& vec)
{
    for (int i{ 0 }; i < vec.size() - 1; i++)
    {
        if (vec.at(i) <= vec.at(i + 1)) continue;
        else error("vector was not sorted correctly");
    }
}

void output(vector<int>& vec)
{
    char wish{};
    cout << "\n\n Möchten Sie die Zahlen in sortierter Form sehen? Geben Sie 'y' für Ja oder 'n' für Nein ein.\n";
    cin >> wish;
    if (wish == 'y') printVector(vec);
    else if (wish == 'n');
    else error("Incorrect char entered at wish.");
}