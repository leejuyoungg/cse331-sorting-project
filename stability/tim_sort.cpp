#include <vector>
#include <limits>
#include <utility>

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

// Merge function for TimSort (pair version, stable)
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

// Final stable version of tim_sort with vector<pair>
void tim_sort(std::vector<std::pair<int, int>>& arr) {
    const int run_size = 32;
    std::vector<int> run_starts;

    int size = arr.size();
    int i = 0;
    while (i + 1 < size) {
        bool is_ascending = arr[i].first <= arr[i + 1].first;
        int start_index = i;
        int probe_index = i + 1;

        run_starts.push_back(start_index);

        // Short run extension
        for (int k = probe_index; (k - start_index + 1 < run_size) && (k < size); ++k) {
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

        // Natural run extension
        while (probe_index + 1 < size) {
            if (is_ascending) {
                if (arr[probe_index].first <= arr[probe_index + 1].first)
                    ++probe_index;
                else break;
            } else {
                if (arr[probe_index].first >= arr[probe_index + 1].first)
                    ++probe_index;
                else break;
            }
        }

        // Do NOT reverse — apply binary insertion sort directly
        if (probe_index >= size) {
            binary_insertion_sort(arr, start_index, size - 1);
        } else {
            binary_insertion_sort(arr, start_index, probe_index);
        }

        i = probe_index + 1;
    }

    // Merge runs pairwise
    for (std::size_t k = 1; k < run_starts.size() - 1; ++k)
        merge_for_tim(arr, 0, run_starts[k] - 1, run_starts[k + 1] - 1);

    if (!run_starts.empty())
        merge_for_tim(arr, 0, run_starts.back() - 1, size - 1);
}
