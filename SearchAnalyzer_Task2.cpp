#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

/*
    CSC252 Assignment 5 - Task 2
    Search Analyzer, Selection Sort, and Recursive Binary Search

    Team Members:
    - Marcus Wiggs
    - Malachi Uche
    - Eduardo Uribe

    This file contains the Task 2 code contribution:
    1. selection_sort()
    2. binary_search() helper function
    3. binary_search_recursive()
    4. SearchAnalyzer class

    Note:
    This code is designed to be integrated into the main Assignment 5 project.
    The SearchAnalyzer class assumes that the project already contains an
    Analyzer base class with:
        - protected int* values;
        - protected int size;
        - a constructor Analyzer(int* values, int size);
        - a virtual string analyze() method.
*/

// Selection sort function
void selection_sort(int* values, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (values[j] < values[minIndex])
            {
                minIndex = j;
            }
        }

        int temp = values[i];
        values[i] = values[minIndex];
        values[minIndex] = temp;
    }
}

// Recursive binary search function
int binary_search_recursive(int* values, int searchedValue, int startIndex, int endIndex)
{
    // Base case: value was not found
    if (startIndex > endIndex)
    {
        return -1;
    }

    int middleIndex = (startIndex + endIndex) / 2;

    // Base case: value was found
    if (values[middleIndex] == searchedValue)
    {
        return middleIndex;
    }

    // Recursive case: search left half
    if (searchedValue < values[middleIndex])
    {
        return binary_search_recursive(values, searchedValue, startIndex, middleIndex - 1);
    }

    // Recursive case: search right half
    return binary_search_recursive(values, searchedValue, middleIndex + 1, endIndex);
}

// Helper binary search function
int binary_search(int* values, int searchedValue, int size)
{
    return binary_search_recursive(values, searchedValue, 0, size - 1);
}

/*
    SearchAnalyzer subclass.

    This class sorts the integer data in the constructor.
    The analyze() method generates 100 random values from 0 to 999
    and uses binary_search() to count how many are found in the data.
*/
class SearchAnalyzer : public Analyzer
{
public:
    SearchAnalyzer(int* values, int size)
        : Analyzer(values, size)
    {
        selection_sort(this->values, this->size);
    }

    string analyze() override
    {
        int foundCount = 0;

        srand(time(0));

        for (int i = 0; i < 100; i++)
        {
            int randomValue = rand() % 1000;

            if (binary_search(values, randomValue, size) != -1)
            {
                foundCount++;
            }
        }

        return "Search Analyzer: Found " + to_string(foundCount) +
               " random values from 0 to 999 in the binary data.";
    }
};
