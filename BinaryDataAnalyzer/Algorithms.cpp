/*
    Signature Assignment: Binary Data Analyzer

    Group Members:
    Marcus Wiggs
    Malachi Uche
    Eduardo Uribe

    Course: CSC252
	Instructor: Professor Hong Shen
	Date: 07/18/2026
    File: Algorithms.cpp

    Purpose:
    Implements selection sort, recursive binary search,
    the binary search helper function, and swap support.
*/

#include "Algorithms.h"

void swap_values(int& firstValue, int& secondValue)
{
    int temporaryValue = firstValue;
    firstValue = secondValue;
    secondValue = temporaryValue;
}

void selection_sort(int* values, int size)
{
    for (int currentIndex = 0;
        currentIndex <= size - 2;
        currentIndex++)
    {
        int smallestIndex = currentIndex;

        for (int searchIndex = currentIndex + 1;
            searchIndex <= size - 1;
            searchIndex++)
        {
            if (values[searchIndex] < values[smallestIndex])
            {
                smallestIndex = searchIndex;
            }
        }

        if (smallestIndex != currentIndex)
        {
            swap_values(
                values[currentIndex],
                values[smallestIndex]
            );
        }
    }
}

int binary_search_recursive(
    const int* values,
    int searchValue,
    int startingIndex,
    int endingIndex
)
{
    if (startingIndex > endingIndex)
    {
        return -1;
    }

    int middleIndex =
        startingIndex +
        (endingIndex - startingIndex) / 2;

    if (values[middleIndex] == searchValue)
    {
        return middleIndex;
    }

    if (searchValue < values[middleIndex])
    {
        return binary_search_recursive(
            values,
            searchValue,
            startingIndex,
            middleIndex - 1
        );
    }

    return binary_search_recursive(
        values,
        searchValue,
        middleIndex + 1,
        endingIndex
    );
}

int binary_search(
    const int* values,
    int searchValue,
    int size
)
{
    return binary_search_recursive(
        values,
        searchValue,
        0,
        size - 1
    );
}