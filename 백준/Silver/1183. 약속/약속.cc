#include <bits/stdc++.h>

int answer;

int main() {
	int N;
	std::cin >> N;

	std::vector<long long> vec;
	for (int i = 0; i < N; i++) {
		long long a, b;
		std::cin >> a >> b;
		vec.push_back(b - a);
	}
	std::sort(vec.begin(), vec.end());

	std::cout << (N % 2 == 1 ? 1 : (vec[N / 2] - vec[N / 2 - 1] + 1));
	return 0;
}