/*
    Signature Assignment: Binary Data Analyzer

    Group Members:
    Marcus Wiggs
    Malachi Uche
    Eduardo Uribe

    Course: CSC252
	Instructor: Professor Hong Shen
	Date: 07/18/2026
    File: DuplicatesAnalyzer.cpp

    Purpose:
    Counts duplicate values found in the binary data.
*/

#include "DuplicatesAnalyzer.h"
#include "Algorithms.h"

#include <sstream>

DuplicatesAnalyzer::DuplicatesAnalyzer(
    const int* inputValues,
    int inputSize
)
    : Analyzer(inputValues, inputSize)
{
}

std::string DuplicatesAnalyzer::analyze()
{
    if (size <= 1)
    {
        return "Duplicates Analyzer: 0 duplicate values.";
    }

    selection_sort(values, size);

    int duplicateCount = 0;

    for (int index = 1; index < size; index++)
    {
        if (values[index] == values[index - 1])
        {
            duplicateCount++;
        }
    }

    std::ostringstream result;

    result << "Duplicates Analyzer: "
        << duplicateCount
        << " duplicate values.";

    return result.str();
}