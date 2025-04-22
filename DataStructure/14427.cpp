#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> vec;
std::vector<int> tree;

// Segment Tree
int InitTree(int begin, int end, int node) {
    if (begin == end)
        return tree[node] = begin;

    int mid = (begin + end) / 2;
    int left_min_index = InitTree(begin, mid, node * 2);
    int right_min_index = InitTree(mid + 1, end, node * 2 + 1);

    if (vec[left_min_index] < vec[right_min_index])
        return tree[node] = left_min_index;
    else if (vec[left_min_index] > vec[right_min_index])
        return tree[node] = right_min_index;
    else
        return tree[node] = std::min(left_min_index, right_min_index);
}

int UpdateTree(int begin, int end, int node, int idx) {
    if (idx < begin || idx > end)
        return tree[node];
    if (begin == end)
        return tree[node] = begin;

    int mid = (begin + end) / 2;
    int left_min_index = UpdateTree(begin, mid, node * 2, idx);
    int right_min_index = UpdateTree(mid + 1, end, node * 2 + 1, idx);

    if (vec[left_min_index] < vec[right_min_index])
        return tree[node] = left_min_index;
    else if (vec[left_min_index] > vec[right_min_index])
        return tree[node] = right_min_index;
    else
        return tree[node] = std::min(left_min_index, right_min_index);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, M;
    std::cin >> N;

    vec.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        std::cin >> vec[i];
    }

    tree.resize(4 * (N + 1));
    InitTree(1, N, 1);

    std::cin >> M;
    for (int i = 0; i < M; i++) {
        int query;
        std::cin >> query;

        if (query == 1) {
            int idx, value;
            std::cin >> idx >> value;
            
            vec[idx] = value;
            UpdateTree(1, N, 1, idx);
        }
        else {
            std::cout << tree[1] << '\n';
        }
    }

    return 0;
}
