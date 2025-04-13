#include "advanced_sort.h"
#include <vector>
#include <climits>
#include <algorithm>
#include <random>
#include <iostream>
#include "../basic_sort/is_sorted.h"
#include <cassert>

using namespace std;

struct LibrarySortState {
    std::vector<int> vec;
    std::vector<int> support_positions;
    int EMPTY = INT_MAX;
    double epsilon = 0.5;
    int inserted = 0;
}; // 빈 칸 나타내는 값 뭘로 할지 고민

void rebalance(LibrarySortState& state, int num_elements);
void find_position_and_insert(LibrarySortState& state, const vector<int>& support_positions, int value);
void insert_value(LibrarySortState& state, int candidate_index, int value); 
void shift_then_insert(LibrarySortState& state, int insert_index, int value);

void rebalance(LibrarySortState& state, int num_elements) {
    int new_size = static_cast<int>((2 + 2* state.epsilon) * num_elements);
    std::vector<int> new_arr(new_size, state.EMPTY);

    std::vector<int> support_elements;
    for (size_t i = 0; i < state.vec.size(); i++) {
        if (state.vec[i] != state.EMPTY) {
            support_elements.push_back(state.vec[i]);
        }
    }

    int gap = new_size / num_elements; 
    size_t index = gap / 2; 

    state.support_positions.clear();
    for (size_t i = 0; i < support_elements.size(); i++) {
        if (index >= new_arr.size()) {
            std::cerr << "[ERROR] rebalance(): index " << index << " out of range! (size = " << new_arr.size() << "gap = " << gap << ")\n";
            exit(1);
        }

        new_arr[index] = support_elements[i];
        state.support_positions.push_back(index);
        index += gap;
    }

    state.vec = new_arr;
}

void find_position_and_insert(LibrarySortState& state, int value) {
    int left = 0;
    int right = state.support_positions.size() - 1;
    
    while (left <= right) { // 이게 끝났다는 건 right < left라는 거
        int mid = (left + right) / 2;
        if (state.vec[state.support_positions[mid]] > value){
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    int insert_pos;
    if (left == 0) {
        insert_pos = state.support_positions[0] / 2;
        insert_value(state, insert_pos, value);
    } else if (left == static_cast<int>(state.support_positions.size())) {
        insert_pos = (state.support_positions.back() + state.vec.size() -1 ) / 2; 
        insert_value(state, insert_pos, value);
    } else {
        insert_pos = (state.support_positions[left - 1] + state.support_positions[left]) / 2;
        insert_value(state, insert_pos, value);
    }
}

void insert_value(LibrarySortState& state, int candidate_index, int value) {
    if (state.vec[candidate_index] == state.EMPTY) {
        state.vec[candidate_index] = value;
    } else {
        shift_then_insert(state, candidate_index, value);
    }
}

void shift_then_insert(LibrarySortState& state, int insert_index, int value) {
    size_t i = insert_index;
    while (i < state.vec.size() && state.vec[i] != state.EMPTY) {
        i = i + 1;
    }
    
    if (i == state.vec.size()) {
        rebalance(state, state.inserted);
        find_position_and_insert(state, value);
        return;
    }

    for (int j = i; j > insert_index; j--) {
        if (state.vec[j - 1] < value) {
            state.vec[j] = value;
            return;
        }

        state.vec[j] = state.vec[j - 1];
    }

    state.vec[insert_index] = value;
}

void library_sort(int* arr, int size) {
    std::vector<int> input(arr, arr + size);
    LibrarySortState state;
    
    int n = input.size();
    int vec_size = static_cast<int>((1 + state.epsilon) * n);
    state.vec = std::vector<int>(vec_size, state.EMPTY);

    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(input.begin(), input.end(), g);

    for (int round = 0; state.inserted < n; round++) {
        int num_to_insert;
        if (round == 0) {
            num_to_insert = 1;
        }
        else {
            num_to_insert = std::min(1 << (round - 1), n - state.inserted);
        }

        for (int i = 0; i < num_to_insert; ++i) {
            int value = input[state.inserted];
            if (state.support_positions.empty()) {
                int pos = vec_size / 2;
                state.vec[pos] = value;
                state.support_positions.push_back(pos);
                state.inserted++;
            } else {
                find_position_and_insert(state, value);
                state.inserted++;
            }
        }
        
        rebalance(state, state.inserted);
    }

    size_t arr_index = 0;
    for (size_t i = 0; i < state.vec.size(); ++i) {
        if (state.vec[i] != state.EMPTY) {
            arr[arr_index++] = state.vec[i];
        }
    }

}