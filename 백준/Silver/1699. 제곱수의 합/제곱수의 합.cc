#include <bits/stdc++.h>

int DP[100001];

int main() {
	int N;
	std::cin >> N;

	for (int i = 1; i <= N; ++i) {
		DP[i] = i;

		for(int j = 1; j * j <= i; ++j) {
			DP[i] = std::min(DP[i], DP[i - j * j] + 1);
		}
	}

	std::cout << DP[N];
	return 0;
}