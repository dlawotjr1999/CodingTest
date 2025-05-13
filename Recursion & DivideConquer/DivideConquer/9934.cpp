#include <iostream>
#include <vector>
#include <cmath>

// https://www.acmicpc.net/problem/9934
// 요약 : 중위 순회로 이루어진 배열을 원래 트리의 레벨대로 출력하는 문제

int tree[1024];
std::vector<int> arr[10];

void Traversal(int start, int end, int depth) {
	if (start >= end)
		return;
	int mid = (start + end) / 2;

	arr[depth].push_back(tree[mid]);	// 현재 레벨의 노드 삽입
	Traversal(start, mid, depth + 1);	// 좌측 하위 노드 탐색
	Traversal(mid + 1, end, depth + 1); // 우측 하위 노드 탐색
}

// Bottom-Up Approach
//int idx = 0;
//void Traversal(int start, int end, int depth) {
//	if (start >= end)
//		return;
//	int mid = (start + end) / 2;
//
//	Traversal(start, mid - 1, depth + 1);
//	arr[depth].push_back(tree[idx++]);
//	Traversal(mid + 1, end, depth + 1);
//}

int main() {
	int K;
	std::cin >> K;

	int size = std::pow(2, K) - 1;
	for (int i = 0; i < size; i++) {
		std::cin >> tree[i];
	}

	Traversal(0, size, 0);

	// 레벨 별 노드들을 출력
	for (int i = 0; i < K; i++) {
		for (auto& elm : arr[i]) {
			std::cout << elm << " ";
		}
		std::cout << "\n";
	}

	return 0;
}