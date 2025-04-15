#include <iostream>
#include <vector>
#include <utility>
#include "stable_sort.h" // bubble_sort 함수가 정의된 헤더 파일 경로로 바꿔주세요

void print_vector(const std::vector<std::pair<int, int>>& arr) {
    for (const auto& p : arr) {
        std::cout << "(" << p.first << ", " << p.second << ") ";
    }
    std::cout << '\n';
}

int main() {
    // 입력: pair.first는 정렬 기준, pair.second는 원래의 위치를 추적하는 인덱스
    std::vector<std::pair<int, int>> data = {
        {3, 0}, {1, 1}, {2, 2}, {3, 3}, {1, 4}
    };

    std::cout << "Before sorting:\n";
    print_vector(data);

    tim_sort(data);

    std::cout << "After sorting:\n";
    print_vector(data);

    return 0;
}
