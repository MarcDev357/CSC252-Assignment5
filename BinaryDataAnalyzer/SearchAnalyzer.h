#pragma once

#include "Analyzer.h"

class SearchAnalyzer : public Analyzer
{
public:
    SearchAnalyzer(const int* inputValues, int inputSize);

    std::string analyze() override;
};