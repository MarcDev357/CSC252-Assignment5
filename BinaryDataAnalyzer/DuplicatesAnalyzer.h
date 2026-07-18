#pragma once

#include "Analyzer.h"

class DuplicatesAnalyzer : public Analyzer
{
public:
    DuplicatesAnalyzer(
        const int* inputValues,
        int inputSize
    );

    std::string analyze() override;
};