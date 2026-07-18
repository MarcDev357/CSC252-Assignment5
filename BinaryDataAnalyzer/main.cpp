#include <iostream>
#include "StatisticsAnalyzer.h"

int main()
{
    int values[] = { 7, 2, 5, 2, 9, 7, 2, 4 };
    int size = sizeof(values) / sizeof(values[0]);

    StatisticsAnalyzer analyzer(values, size);

    std::cout << "Statistics Analysis\n";
    std::cout << "-------------------\n";
    std::cout << analyzer.analyze() << '\n';

    return 0;
}