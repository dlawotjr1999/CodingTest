#include <bits/stdc++.h>

int main() {
	int N; std::cin >> N;

	std::vector<int> holes;
	std::vector<int> acorns;

	int hole = 0;
	for (int i = 0; i < N; ++i) {
		int temp; std::cin >> temp;
		hole = std::max(hole, temp + i);
		holes.push_back(hole);
	}

	int Q; std::cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int acorn; std::cin >> acorn;
		acorns.push_back(acorn);
	}

	for (int i = 0; i < Q; ++i) {
		int idx = std::lower_bound(holes.begin(), holes.end(), acorns[i]) - holes.begin() + 1;
		std::cout << idx << ' ';
	}
}