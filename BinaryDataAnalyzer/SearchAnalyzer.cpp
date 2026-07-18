/*
    Signature Assignment: Binary Data Analyzer

    Group Members:
    Marcus Wiggs
    Malachi Uche
    Eduardo Uribe

    Course: CSC252
	Instructor: Professor Hong Shen
	Date: 07/18/2026
    File: SearchAnalyzer.cpp

    Purpose:
    Sorts analyzer data and performs 100 random searches
    using recursive binary search.
*/

#include "SearchAnalyzer.h"
#include "Algorithms.h"

#include <cstdlib>
#include <sstream>

SearchAnalyzer::SearchAnalyzer(
    const int* inputValues,
    int inputSize
)
    : Analyzer(inputValues, inputSize)
{
    selection_sort(values, size);
}

std::string SearchAnalyzer::analyze()
{
    int foundCount = 0;

    for (int count = 0; count < 100; count++)
    {
        int randomValue = std::rand() % 1000;

        if (binary_search(
            values,
            randomValue,
            size
        ) != -1)
        {
            foundCount++;
        }
    }

    std::ostringstream result;

    result << "Search Analyzer: Found "
        << foundCount
        << " of 100 random values.";

    return result.str();
}