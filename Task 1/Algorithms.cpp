#include "Algorithms.h"

// Support function needed by selection sort
void swap_values(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(int* values, int size) {
    for (int currentIndex = 0; currentIndex <= size - 2; ++currentIndex) {
        int smallestIndex = currentIndex;

        for (int searchIndex = currentIndex + 1; searchIndex <= size - 1; ++searchIndex) {
            if (values[searchIndex] < values[smallestIndex]) {
                smallestIndex = searchIndex;
            }
        }

        if (smallestIndex != currentIndex) {
            swap_values(values[currentIndex], values[smallestIndex]);
        }
    }
}

int binary_search_recursive(const int* values, int searchValue, int startingIndex, int endingIndex) {
    if (startingIndex > endingIndex) {
        return -1;
    }

    int middleIndex = startingIndex + (endingIndex - startingIndex) / 2;

    if (values[middleIndex] == searchValue) {
        return middleIndex;
    }
    else if (searchValue < values[middleIndex]) {
        return binary_search_recursive(values, searchValue, startingIndex, middleIndex - 1);
    }
    else {
        return binary_search_recursive(values, searchValue, middleIndex + 1, endingIndex);
    }
}

int binary_search(const int* values, int searchValue, int size) {
    int startingIndex = 0;
    int endingIndex = size - 1;
    return binary_search_recursive(values, searchValue, startingIndex, endingIndex);
}