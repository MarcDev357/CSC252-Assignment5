#pragma once

#include "Analyzer.h"

class StatisticsAnalyzer : public Analyzer
{
public:
    StatisticsAnalyzer(int* inputValues, int inputSize)
        : Analyzer(inputValues, inputSize)
    {
    }

    std::string analyze() override;
};