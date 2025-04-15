#include <vector>
#include <limits>
#include <algorithm>
#include <utility>
#include "stable_sort.h"

// Binary Insertion Sort for pair
void binary_insertion_sort(std::vector<std::pair<int, int>>& arr, int start, int end) {
    for (int k = start + 1; k <= end; ++k) {
        auto key = arr[k];
        int left = start;
        int right = k - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid].first > key.first)
                right = mid - 1;
            else
                left = mid + 1;
        }

        for (int j = k - 1; j >= left; --j)
            arr[j + 1] = arr[j];
        arr[left] = key;
    }
}

// Merge function for TimSort
void merge_for_tim(std::vector<std::pair<int, int>>& arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    std::vector<std::pair<int, int>> left_arr(n1 + 1);
    std::vector<std::pair<int, int>> right_arr(n2 + 1);

    for (int i = 0; i < n1; ++i)
        left_arr[i] = arr[p + i];
    for (int j = 0; j < n2; ++j)
        right_arr[j] = arr[q + 1 + j];

    left_arr[n1] = {std::numeric_limits<int>::max(), -1};
    right_arr[n2] = {std::numeric_limits<int>::max(), -1};

    int i = 0, j = 0;
    for (int k = p; k <= r; ++k) {
        if (left_arr[i].first <= right_arr[j].first)
            arr[k] = left_arr[i++];
        else
            arr[k] = right_arr[j++];
    }
}

// TimSort for vector<pair<int, int>> (stable)
void tim_sort(std::vector<std::pair<int, int>>& arr) {
    int size = arr.size();
    const int RUN = 32;
    std::vector<int> run_starts;

    int i = 0;
    while (i < size) {
        int start = i;
        int end = std::min(i + RUN - 1, size - 1);

        binary_insertion_sort(arr, start, end);
        run_starts.push_back(start);

        i = end + 1;
    }

    // Merge runs pairwise
    while (run_starts.size() > 1) {
        std::vector<int> new_run_starts;

        for (size_t i = 0; i + 1 < run_starts.size(); i += 2) {
            int start = run_starts[i];
            int mid = run_starts[i + 1] - 1;
            int end = (i + 2 < run_starts.size()) ? run_starts[i + 2] - 1 : size - 1;

            merge_for_tim(arr, start, mid, end);
            new_run_starts.push_back(start);
        }

        if (run_starts.size() % 2 == 1) {
            new_run_starts.push_back(run_starts.back());
        }

        run_starts = new_run_starts;
    }
}
