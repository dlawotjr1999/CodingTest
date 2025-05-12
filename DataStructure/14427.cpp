#include <iostream>
#include <vector>
#include <algorithm>

// 길이가 N인 수열이 주어졌을 때, 다음 쿼리를 구현하는 문제
// 1 i v : A_i를 v로 변경
// 2 : 수열에서 크기가 가장 작은 값의 인덱스를 출력하며, 그러한 값이 여러 개인 경우에는 인덱스가 작은 것을 출력

// 세그먼트 트리 : https://m.blog.naver.com/ndb796/221282210534

std::vector<int> vec;
std::vector<int> tree;

// Segment Tree Initialization
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

// Function to update the element 
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
