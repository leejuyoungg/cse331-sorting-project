#include "advanced_sort.h"
#include <vector>

using namespace std;

struct tree {
    int value;
    vector<tree*> children;

    tree(int v) : value(v) {}
};

void delete_tree(tree* node) {
    if (!node) return;
    for (size_t i = 0; i < node->children.size(); ++i) {
        delete_tree(node->children[i]);
    }
    delete node;
}

tree* tournament_play(tree* X, tree* Y) {
    if (X->value <= Y->value) {
        X->children.push_back(Y);
        return X;
    } else {
        Y->children.push_back(X);
        return Y;
    }
}

tree* tournament(vector<tree*>& forest) {
    while (forest.size() > 1) {
        vector<tree*> next_round;
        for (size_t i = 0; i + 1 < forest.size(); i += 2) {
            next_round.push_back(tournament_play(forest[i], forest[i + 1]));
        }
        if (forest.size() % 2 == 1) {
            next_round.push_back(forest[forest.size() - 1]);
        }
        forest = move(next_round);
    }
    return forest.front();
}

/*rebuild_tournament 굳이 하지 말고 build_tournament_tree(root->childre)  호출하자*/

void tournament_sort(int* arr, int size) {
    vector<tree*> forest;
    for (int i = 0; i < size; ++i) {
        forest.push_back(new tree(arr[i]));
    }

    vector<int> result;
    tree* tournament_tree = tournament(forest);

    while (tournament_tree) {
        result.push_back(tournament_tree->value);

        if (tournament_tree->children.empty()) {
            delete_tree(tournament_tree);  // ✅ 마지막 루트 노드 해제
            tournament_tree = nullptr;
        } else {
            vector<tree*> next = tournament_tree->children;  // 얕은 복사 안전함
            delete tournament_tree;  // ✅ 현재 루트만 해제 (자식은 남겨야 하므로 delete_tree 아님)
            tournament_tree = tournament(next);
        }
    }
    
    for (int i = 0; i < size; i++) {
        arr[i] = result[i];
    }
}