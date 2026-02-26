#include <bits/stdc++.h>

int answer;

int main() {
	int N; std::cin >> N;

	std::vector<int> U(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> U[i];
	}

	std::unordered_set<int> temp;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			temp.insert(U[i] + U[j]);
		}
	}

	for (int i = 0; i < N; ++i) {
		int cur = U[i];
		for (int j = 0; j < N; ++j) {
			if (temp.find(cur - U[j]) != temp.end())
				answer = std::max(answer, cur);
		}
	}

	std::cout << answer;
	return 0;
}