#ifndef ALGORITHMS_H
#define ALGORITHMS_H

// Implement selection_sort()
void selection_sort(int* values, int size);

// Implement the binary_search() helper function
int binary_search(const int* values, int searchValue, int size);

// Implement the recursive binary_search_recursive() function
int binary_search_recursive(const int* values, int searchValue, int startingIndex, int endingIndex);

// Add any support functions needed by selection sort
void swap_values(int& a, int& b);

#endif // ALGORITHMS_H