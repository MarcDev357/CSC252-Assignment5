#include <iostream>
#include "Algorithms.h"

void print_array(const int* values, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << values[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    // 1. Unsorted & Duplicate Values[cite: 1]
    int testArray[] = { 45, 12, 78, 12, 4, 89, 2, 33 };
    int size = sizeof(testArray) / sizeof(testArray[0]);

    std::cout << "Original Array: ";
    print_array(testArray, size);

    selection_sort(testArray, size);

    // 2. Sorted Values[cite: 1]
    std::cout << "Sorted Array:   ";
    print_array(testArray, size);

    // 3. Search for an existing value
    int searchVal1 = 78;
    int index1 = binary_search(testArray, searchVal1, size);
    std::cout << "Index of " << searchVal1 << ": " << index1 << "\n";

    // 4. Missing values[cite: 1]
    int searchVal2 = 100;
    int index2 = binary_search(testArray, searchVal2, size);
    std::cout << "Index of " << searchVal2 << " (Missing): " << index2 << "\n";

    return 0;
}