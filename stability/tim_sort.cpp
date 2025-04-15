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
        bool is_ascending = true;
        if (i + 1 < size)
            is_ascending = arr[i].first <= arr[i + 1].first;

        int start_index = i;
        int probe_index = i + 1;

        run_starts.push_back(start_index);

        // Extend short run via binary insertion sort (<= RUN size)
        for (int k = probe_index; (k - start_index + 1 < RUN) && (k < size); ++k) {
            probe_index = k;
            auto key = arr[k];
            int left = start_index;
            int right = k - 1;

            while (left <= right) {
                int mid = (left + right) / 2;
                if (is_ascending) {
                    if (arr[mid].first > key.first)
                        right = mid - 1;
                    else
                        left = mid + 1;
                } else {
                    if (arr[mid].first < key.first)
                        right = mid - 1;
                    else
                        left = mid + 1;
                }
            }

            for (int j = k - 1; j >= left; --j)
                arr[j + 1] = arr[j];
            arr[left] = key;
        }

        // Scan rest of the natural run
        while (probe_index + 1 < size) {
            if (is_ascending) {
                if (arr[probe_index].first <= arr[probe_index + 1].first)
                    ++probe_index;
                else
                    break;
            } else {
                if (arr[probe_index].first >= arr[probe_index + 1].first)
                    ++probe_index;
                else
                    break;
            }
        }

        // If descending, reverse the run
        if (!is_ascending) {
            std::reverse(arr.begin() + start_index, arr.begin() + probe_index + 1);
        }

        // Binary insertion sort on entire run
        binary_insertion_sort(arr, start_index, probe_index);

        i = probe_index + 1;
    }

    // Merge runs pairwise
    for (std::size_t k = 1; k + 1 < run_starts.size(); ++k)
        merge_for_tim(arr, 0, run_starts[k] - 1, run_starts[k + 1] - 1);

    if (!run_starts.empty())
        merge_for_tim(arr, 0, run_starts.back() - 1, size - 1);
}
