#include "advanced_sort.h"
#include <vector>
#include <limits>
#include <iostream>

void merge_for_tim(int* arr, int p, int q, int r);
void binary_insertion_sort(int* arr, int start, int end);

void binary_insertion_sort(int* arr, int start, int end) {
    for (int k = start + 1; k <= end; ++k) {
        int key = arr[k];
        int left = start;
        int right = k - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] > key) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        for (int j = k - 1; j >= left; --j) {
            arr[j + 1] = arr[j];
        }
        arr[left] = key;
    }
}

void merge_for_tim(int* arr, int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;
    int* left_arr = new int[n1 + 1];
    int* right_arr = new int[n2 + 1];
    for (int i = 0; i < n1; i++) {
        left_arr[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        right_arr[j] = arr[q + 1 + j];
    }
    left_arr[n1] = std::numeric_limits<int>::max();
    right_arr[n2] = std::numeric_limits<int>::max();
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++) {
        if (left_arr[i] <= right_arr[j]) {
            arr[k] = left_arr[i];
            i = i + 1;
        }
        else {
            arr[k] = right_arr[j];
            j = j + 1;
        }
    }

    delete [] left_arr;
    delete [] right_arr;
}

void tim_sort(int* arr, int size) {
    bool is_ascending = true;
    int run_size = 32;
    std::vector<int> run_starts;

    int i = 0;
    while (i + 1 < size) {
        is_ascending = arr[i] <= arr[i + 1]; // 등호 붙일지 말지 고민
        int start_index = i;
        int probe_index = i + 1; /* i + 2를 i + 1로 바꿈*/
        run_starts.push_back(start_index);
        if (is_ascending) {
            for (int k = probe_index; (k - start_index + 1 < run_size) && (k < size); k++) {
                probe_index = k;
                int key = arr[k];
                int left = start_index;
                int right = k - 1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (arr[mid] > key) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                for (int j = k - 1; j >= left; j--) {
                    arr[j + 1] = arr[j];
                }
                arr[left] = key;
            }
            while (probe_index + 1 < size) {
                if (arr[probe_index] <= arr[probe_index + 1]){
                    probe_index = probe_index + 1;
                }
                else {
                    break;
                }
            }
        }
        else {
            for (int k = probe_index; (k - start_index + 1 < run_size) && (k < size); k++) {
                probe_index = k;
                int key = arr[k];
                int left = start_index;
                int right = k - 1;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (arr[mid] < key) {
                        right = mid - 1;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                for (int j = k - 1; j >= left; j--) {
                    arr[j + 1] = arr[j];
                }
                arr[left] = key;
            }
            while (probe_index + 1 < size) {
                if (arr[probe_index] >= arr[probe_index + 1]){
                    probe_index = probe_index + 1;
                }
                else {
                    break;
                }
            }
            /*if (probe_index >= size) {
                for (int k = 0; k <= size - 1; k++) {
                    std::cout << arr[k] << " ";
                }
                std::cout << "\n";
            }
            else {
                for (int k = 0; k <= probe_index; k++) {
                    std::cout << arr[k] << " ";
                }
                std::cout << "\n";
            }*/
            if (probe_index >= size) {
                binary_insertion_sort(arr, start_index, size - 1);
            }
            else {
                binary_insertion_sort(arr, start_index, probe_index);
            }
        }
        /*if (probe_index >= size) {
            for (int k = 0; k <= size - 1; k++) {
                std::cout << arr[k] << " ";
            }
            std::cout << "\n";
        }
        else {
            for (int k = 0; k <= probe_index; k++) {
                std::cout << arr[k] << " ";
            }
            std::cout << "\n";
        }*/
        i = probe_index + 1;

    }
    //std::cout << "insertion done" << std::endl;
    for (std::size_t k = 1; k < run_starts.size() - 1; k++) {
        merge_for_tim(arr, 0, run_starts[k] - 1, run_starts[k + 1] - 1);
        /*for (int k = 0; k < size; k++) {
            std::cout << arr[k] << " ";
        }
        std::cout << "\n";*/
    }
    merge_for_tim(arr, 0, run_starts[run_starts.size() - 1] - 1, size - 1);
    /*for (int k = 0; k < size; k++) {
        std::cout << arr[k] << " ";
    }
    std::cout << "\n";*/
}