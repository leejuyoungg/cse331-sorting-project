#include <vector>
#include <algorithm>
#include "stable_sort.h"

// Stable cocktail shaker sort for vector<pair<int, int>>
void cocktail_shaker_sort(std::vector<std::pair<int, int>>& arr) {
    int start = 0;
    int end = arr.size() - 1;

    while (start < end) {
        int last_swap = start;

        // Forward pass
        for (int i = start; i < end; i++) {
            if (arr[i].first > arr[i + 1].first) {
                std::swap(arr[i], arr[i + 1]);
                last_swap = i;
            }
        }
        end = last_swap;

        // Backward pass
        for (int i = end; i > start; i--) {
            if (arr[i].first < arr[i - 1].first) {
                std::swap(arr[i], arr[i - 1]);
                last_swap = i;
            }
        }
        start = last_swap;
    }
}
