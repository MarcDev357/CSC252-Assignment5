/*
    Signature Assignment: Binary Data Analyzer

    Group Members:
    Marcus Wiggs
    Malachi Uche
    Eduardo Uribe

    Course: CSC252
	Instructor: Professor Hong Shen
	Date: 07/18/2026
    File: Analyzer.cpp

    Purpose:
    Implements the Analyzer base-class constructor,
    value-cloning function, and virtual destructor.
*/

#include "Analyzer.h"

Analyzer::Analyzer(
    const int* inputValues,
    int inputSize
)
    : values(nullptr), size(inputSize)
{
    cloneValues(inputValues);
}

void Analyzer::cloneValues(const int* inputValues)
{
    if (inputValues == nullptr || size <= 0)
    {
        values = nullptr;
        size = 0;
        return;
    }

    values = new int[size];

    for (int index = 0; index < size; index++)
    {
        values[index] = inputValues[index];
    }
}

Analyzer::~Analyzer()
{
    delete[] values;
}