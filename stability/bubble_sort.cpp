#include <vector>
#include <algorithm>
#include "stable_sort.h"

// Stable Bubble Sort for vector of pairs
// Sorts by pair.first while preserving relative order of same first values
void bubble_sort(std::vector<std::pair<int, int>>& arr) {
    int n = arr.size();
    while (n > 1) {
        int new_n = 0;
        for (int i = 0; i < n - 1; i++) {
            // Sort by first element of the pair
            if (arr[i].first > arr[i + 1].first) {
                std::swap(arr[i], arr[i + 1]);
                new_n = i + 1;
            }
        }
        n = new_n;
    }
}
