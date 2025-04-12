#include "advanced_sort.h"
#include "../basic_sort/basic_sort.h"
#include <algorithm>
#include <iostream>

void comb_sort(int* arr, int size) {
    double shrink_factor = 1.3;
    int gap = size;

    while (gap > 1) {
        gap = gap / shrink_factor;

        for (int i = 0; i < size - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                std::swap(arr[i], arr[i + gap]);
            }
        }
    }

    bubble_sort(arr, size);
}