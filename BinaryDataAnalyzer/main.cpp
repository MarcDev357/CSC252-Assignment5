/*
    Signature Assignment: Binary Data Analyzer

    Group Members:
    Marcus Wiggs
    Malachi Uche
    Eduardo Uribe

    Course: CSC252
    Instructor: Professor Hong Shen
    Date: 07/18/2026
    File: main.cpp

    Purpose:
    Creates a binary data file, reads its integer values,
    and analyzes the data using polymorphic analyzer classes.
*/

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

#include "Analyzer.h"
#include "BinaryReader.h"
#include "DuplicatesAnalyzer.h"
#include "MissingAnalyzer.h"
#include "SearchAnalyzer.h"
#include "StatisticsAnalyzer.h"

int main()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    const std::string fileName = "binaryData.dat";
    const int numberOfValues = 100;

    createBinaryFile(fileName, numberOfValues);

    BinaryReader reader;

    if (!reader.read(fileName))
    {
        std::cout << "Error: Unable to read the binary file.\n";
        return 1;
    }

    std::cout << "Binary Data Analyzer\n";
    std::cout << "====================\n\n";

    std::cout << "Values read from binary file: "
        << reader.getSize()
        << "\n\n";

    Analyzer* analyzers[] =
    {
        new DuplicatesAnalyzer(
            reader.getValues(),
            reader.getSize()
        ),

        new MissingAnalyzer(
            reader.getValues(),
            reader.getSize()
        ),

        new SearchAnalyzer(
            reader.getValues(),
            reader.getSize()
        ),

        new StatisticsAnalyzer(
            reader.getValues(),
            reader.getSize()
        )
    };

    const int analyzerCount =
        sizeof(analyzers) / sizeof(analyzers[0]);

    const std::string sectionTitles[] =
    {
        "Duplicate Analysis",
        "Missing Value Analysis",
        "Search Analysis",
        "Statistics Analysis"
    };

    for (int index = 0; index < analyzerCount; index++)
    {
        std::cout << "----- "
            << sectionTitles[index]
            << " -----\n";

        std::cout << analyzers[index]->analyze()
            << "\n\n";

        delete analyzers[index];
    }

    return 0;
}