#include <vector>
#include <utility>
#include "stable_sort.h"

// Stable insertion sort for vector<pair<int, int>>
void insertion_sort(std::vector<std::pair<int, int>>& arr) {
    int size = arr.size();
    for (int j = 1; j < size; j++) {
        auto key = arr[j];  // 현재 삽입할 요소
        int i = j - 1;

        // pair.first 기준으로 비교
        while (i >= 0 && arr[i].first > key.first) {
            arr[i + 1] = arr[i]; // 한 칸씩 뒤로 밀기
            i--;
        }

        arr[i + 1] = key; // 원래 위치에 삽입
    }
}
