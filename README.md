# CSC252 Assignment 5 - Binary Data Analyzer

## Project Overview

The Binary Data Analyzer is a C++ console application that creates a binary file containing random integer values, reads the values back into memory, and analyzes the data through a class hierarchy that demonstrates inheritance, polymorphism, dynamic memory management, sorting, recursion, and binary file input/output.

## Group Members

- Marcus Wiggs - Group Lead, StatisticsAnalyzer, final integration, testing, README, and pseudocode
- Malachi Uche - Selection sort and recursive binary search functions
- Eduardo Uribe - SearchAnalyzer implementation and random-search testing

## Course Information

- Course: CSC252
- Assignment: Signature Assignment 5
- Instructor: ______________________________
- Submission Date: July 18, 2026

## Main Features

- Creates a binary data file containing 100 random integers from 0 through 999.
- Reads binary integer data using the BinaryReader class.
- Uses an Analyzer abstract base class with a pure virtual analyze() method.
- Clones input values so each analyzer works with an independent copy of the data.
- Uses a virtual destructor to safely release dynamically allocated memory.
- Implements selection sort.
- Implements a recursive binary search and helper function.
- Uses polymorphism to run multiple analyzer subclasses through Analyzer pointers.
- Reports duplicate values, missing values, random search results, and descriptive statistics.

## Analyzer Classes

### DuplicatesAnalyzer
Sorts the data and counts repeated values.

### MissingAnalyzer
Sorts the data and counts integers missing between the minimum and maximum values.

### SearchAnalyzer
Sorts the analyzer's copied data in the constructor, generates 100 random integers from 0 through 999, searches for each value using recursive binary search, and reports how many were found.

### StatisticsAnalyzer
Sorts the data and calculates:

- Minimum
- Maximum
- Mean
- Median
- Mode

When multiple values tie for mode, the first value in sorted order is selected.

## Project Structure

```text
CSC252-Assignment5/
|-- CSC252-Assignment5.sln
|-- README.md
|-- BinaryDataAnalyzer/
|   |-- Algorithms.h
|   |-- Algorithms.cpp
|   |-- Analyzer.h
|   |-- Analyzer.cpp
|   |-- BinaryReader.h
|   |-- BinaryReader.cpp
|   |-- DuplicatesAnalyzer.h
|   |-- DuplicatesAnalyzer.cpp
|   |-- MissingAnalyzer.h
|   |-- MissingAnalyzer.cpp
|   |-- SearchAnalyzer.h
|   |-- SearchAnalyzer.cpp
|   |-- StatisticsAnalyzer.h
|   |-- StatisticsAnalyzer.cpp
|   |-- main.cpp
|   |-- BinaryDataAnalyzer.vcxproj
|   `-- BinaryDataAnalyzer.vcxproj.filters
`-- Binary_Data_Analyzer_Pseudocode.docx
```

## Build and Run Instructions

1. Open `CSC252-Assignment5.sln` in Microsoft Visual Studio.
2. Select `Debug` and `x64` from the toolbar.
3. Choose **Build > Rebuild Solution**.
4. Confirm the project builds with zero errors and zero warnings.
5. Press `Ctrl + F5` to run without debugging.

The program creates `binaryData.dat` at runtime, reads 100 integers from the file, and displays results for each analyzer.

## Example Output

```text
Binary Data Analyzer
====================

Values read from binary file: 100

----- Duplicate Analysis -----
Duplicates Analyzer: 4 duplicate values.

----- Missing Value Analysis -----
Missing Analyzer: 889 missing values between the minimum and maximum.

----- Search Analysis -----
Search Analyzer: Found 14 of 100 random values.

----- Statistics Analysis -----
Minimum: 1
Maximum: 985
Mean: 483.32
Median: 458.50
Mode: 339
```

Because the program uses random values, the results vary each time it runs.

## Testing Completed

- Selection sort tested with unsorted, sorted, reverse-order, duplicate, one-element, and empty arrays.
- Binary search tested with first, middle, last, and missing values.
- SearchAnalyzer verified to perform exactly 100 searches in the range 0 through 999.
- StatisticsAnalyzer verified with odd and even data sizes.
- Mode tie behavior verified to keep the first value.
- Binary file creation and reading verified.
- Polymorphic execution through Analyzer pointers verified.
- Project rebuilt with zero errors and zero warnings.

## Submission Notes

Each group member must submit the complete Visual Studio project and pseudocode document separately. The final ZIP file should include this README, the Visual Studio solution and project files, the source code, and `Binary_Data_Analyzer_Pseudocode.docx`.
