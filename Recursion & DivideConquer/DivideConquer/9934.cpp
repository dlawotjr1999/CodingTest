#include <iostream>
#include <vector>
#include <cmath>

int tree[1024];
std::vector<int> arr[10];

void Traversal(int start, int end, int depth) {
	if (start >= end)
		return;
	int mid = (start + end) / 2;

	arr[depth].push_back(tree[mid]);
	Traversal(start, mid, depth + 1);
	Traversal(mid + 1, end, depth + 1);
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

	for (int i = 0; i < K; i++) {
		for (auto& elm : arr[i]) {
			std::cout << elm << " ";
		}
		std::cout << "\n";
	}

	return 0;
}