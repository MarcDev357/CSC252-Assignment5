/*
    Signature Assignment: Binary Data Analyzer

    Group Members:
    Marcus Wiggs
    Malachi Uche
    Eduardo Uribe

    Course: CSC252
	Instructor: Professor Hong Shen
	Date: 07/18/2026
    File: MissingAnalyzer.cpp

    Purpose:
    Counts missing integer values between the minimum
    and maximum values in the binary data.
*/

#include "MissingAnalyzer.h"
#include "Algorithms.h"

#include <sstream>

MissingAnalyzer::MissingAnalyzer(
    const int* inputValues,
    int inputSize
)
    : Analyzer(inputValues, inputSize)
{
}

std::string MissingAnalyzer::analyze()
{
    if (size == 0)
    {
        return "Missing Analyzer: No data available.";
    }

    selection_sort(values, size);

    int missingCount = 0;

    for (int index = 1; index < size; index++)
    {
        int difference =
            values[index] - values[index - 1];

        if (difference > 1)
        {
            missingCount += difference - 1;
        }
    }

    std::ostringstream result;

    result << "Missing Analyzer: "
        << missingCount
        << " missing values between the minimum and maximum.";

    return result.str();
}