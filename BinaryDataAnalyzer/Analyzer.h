#pragma once

#include <string>

class Analyzer
{
protected:
    int* values;
    int size;

public:
    Analyzer(int* inputValues, int inputSize)
        : values(inputValues), size(inputSize)
    {
    }

    virtual std::string analyze() = 0;

    virtual ~Analyzer() = default;
};