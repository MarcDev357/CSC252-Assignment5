#pragma once

#include "Analyzer.h"

class MissingAnalyzer : public Analyzer
{
public:
    MissingAnalyzer(
        const int* inputValues,
        int inputSize
    );

    std::string analyze() override;
};