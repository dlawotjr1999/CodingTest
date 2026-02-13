#include <bits/stdc++.h>

int answer;

int main() {
	int N, K;
	std::cin >> N >> K;

	std::vector<int> order(K);
	std::vector<int> tab(N, 0);

	for (int i = 0; i < K; ++i) {
		std::cin >> order[i];
	}

	for (int i = 0; i < K; ++i) {
		bool flag = false;

		for (int j = 0; j < N; ++j) {
			if (order[i] == tab[j]) {
				flag = true;
				break;
			}
		}
		if (flag) continue;

		for (int j = 0; j < N; ++j) {
			if (tab[j] == 0) {
				tab[j] = order[i];
				flag = true;
				break;
			}
		}
		if (flag) continue;

		int pos = -1;
		int idx = -1;

		for (int j = 0; j < N; ++j) {
			int temp = 0;

			for (int k = i + 1; k < K; ++k) {
				if (tab[j] == order[k])
					break;
				temp++;
			}
			if (temp > idx) {
				pos = j;
				idx = temp;
			}
		}
		tab[pos] = order[i];
		answer++;
	}

	std::cout << answer;
	return 0;
}