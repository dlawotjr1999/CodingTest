#include <bits/stdc++.h>

int N;
long long total, half;
std::vector<std::vector<int>> field;

long long BinarySearch(int low, int high) {
	int answer = 1e8;
	int l = low, r = high;

	while (l <= r) {
		long long cnt = 0;
		int mid = (l + r) / 2;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				int cur = std::min(field[i][j], mid);
				cnt += (1LL * cur);
			}
		}

		if (cnt >= half) {
			answer = std::min(mid, answer);
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	return answer;
}

int main() {
	std::cin >> N;
	field.resize(N, std::vector<int>(N));

	int min_h = 0, max_h = -1;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> field[i][j];
			total += field[i][j];
			max_h = std::max(max_h, field[i][j]);
		}
	}

	half = (total + 1) / 2;
	std::cout << BinarySearch(min_h, max_h);
	return 0;
}