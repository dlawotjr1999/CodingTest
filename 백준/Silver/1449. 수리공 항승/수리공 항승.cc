#include <bits/stdc++.h>

int answer;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, L;
	std::cin >> N >> L;

	std::vector<double> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	std::sort(vec.begin(), vec.end());

	double cur = 0;
	for (int i = 0; i < N; ++i) {
		if (vec[i] > cur) {
			answer++;
			
			int s = vec[i] - 0.5f;
			int e = s + L + 0.5f;
			cur = e;
		}
	}

	std::cout << answer;
	return 0;
}