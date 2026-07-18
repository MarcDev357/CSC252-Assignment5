/*
    Signature Assignment: Binary Data Analyzer

    Group Members:
    Marcus Wiggs
    Malachi Uche
    Eduardo Uribe

    Course: CSC252
	Instructor: Professor Hong Shen
	Date: 07/18/2026
    File: StatisticsAnalyzer.cpp

    Purpose:
    Sorts binary data and calculates the minimum,
    maximum, mean, median, and mode.
*/

#include "StatisticsAnalyzer.h"

#include <iomanip>
#include <sstream>
#include "Algorithms.h"

std::string StatisticsAnalyzer::analyze()
{
    if (size == 0)
    {
        return "No statistics are available.";
    }

    selection_sort(values, size);

    int minimumValue = values[0];
    int maximumValue = values[size - 1];

    double sum = 0.0;

    for (int index = 0; index < size; index++)
    {
        sum += values[index];
    }

    double mean = sum / size;
    double median = 0.0;

    if (size % 2 == 1)
    {
        median = values[size / 2];
    }
    else
    {
        int rightMiddleIndex = size / 2;
        int leftMiddleIndex = rightMiddleIndex - 1;

        median =
            (static_cast<double>(values[leftMiddleIndex]) +
                static_cast<double>(values[rightMiddleIndex])) /
            2.0;
    }

    int mode = values[0];
    int highestFrequency = 1;
    int currentFrequency = 1;

    for (int index = 1; index < size; index++)
    {
        if (values[index] == values[index - 1])
        {
            currentFrequency++;
        }
        else
        {
            if (currentFrequency > highestFrequency)
            {
                highestFrequency = currentFrequency;
                mode = values[index - 1];
            }

            currentFrequency = 1;
        }
    }

    if (currentFrequency > highestFrequency)
    {
        mode = values[size - 1];
    }

    std::ostringstream result;

    result << std::fixed << std::setprecision(2);
    result << "Minimum: " << minimumValue << '\n';
    result << "Maximum: " << maximumValue << '\n';
    result << "Mean: " << mean << '\n';
    result << "Median: " << median << '\n';
    result << "Mode: " << mode;

    return result.str();
}