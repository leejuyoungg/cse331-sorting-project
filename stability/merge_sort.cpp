#include <vector>
#include <limits>
#include <utility>
#include "stable_sort.h"

// Stable merge: compares pair.first and preserves input order
void merge(std::vector<std::pair<int, int>>& arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<std::pair<int, int>> left_arr(n1 + 1);
    std::vector<std::pair<int, int>> right_arr(n2 + 1);

    for (int i = 0; i < n1; i++)
        left_arr[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        right_arr[j] = arr[q + 1 + j];

    // Sentinel 값: 최대값의 pair를 사용하여 무한대 역할
    left_arr[n1] = {std::numeric_limits<int>::max(), -1};
    right_arr[n2] = {std::numeric_limits<int>::max(), -1};

    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (left_arr[i].first <= right_arr[j].first) {
            arr[k] = left_arr[i++];
        } else {
            arr[k] = right_arr[j++];
        }
    }
}

// Recursive merge sort
void merge_sort(std::vector<std::pair<int, int>>& arr, int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(arr, p, q);
        merge_sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
