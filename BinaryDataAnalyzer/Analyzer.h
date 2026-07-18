#pragma once

#include <string>

class Analyzer
{
protected:
    int* values;
    int size;

    void cloneValues(const int* inputValues);

public:
    Analyzer(const int* inputValues, int inputSize);
    virtual ~Analyzer();

    virtual std::string analyze() = 0;
};