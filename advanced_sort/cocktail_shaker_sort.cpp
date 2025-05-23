#include "advanced_sort.h"
#include <algorithm>

void cocktail_shaker_sort(int* arr, int size) {
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int last_swap = start;

        // Forward pass
        for (int i = start; i < end; i++) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                last_swap = i;
            }
        }
        end = last_swap;

        // Backward pass
        for (int i = end; i > start; i--) {
            if (arr[i] < arr[i - 1]) {
                std::swap(arr[i], arr[i - 1]);
                last_swap = i;
            }
        }
        start = last_swap;
    }
}
