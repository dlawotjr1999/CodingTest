#include <bits/stdc++.h>

const int MOD = 1000000000;
const int MAX = (1 << 10) - 1;

int N;
int answer;

int main() {
	std::cin >> N;

	// DP[len][digit][mask] : 길이가 len이고 마지막 숫자가 digit이며, 그 숫자들이 mask에 표시된 숫자들만 사용된 경우
	std::vector<std::vector<std::vector<int>>> DP(N + 1, std::vector<std::vector<int>>(10, std::vector<int>(1 << 10, 0)));

	for (int i = 1; i <= 9; ++i) {
		DP[1][i][1 << i] = 1;
	}

	for (int len = 2; len <= N; ++len) {
		for (int digit = 0; digit <= 9; ++digit) {
			for (int mask = 0; mask <= MAX; ++mask) {
				int cur = DP[len - 1][digit][mask];
				if (cur == 0)
					continue;

				if (digit > 0) {
					int next = digit - 1;
					int cur_mask = mask | (1 << next);
					DP[len][next][cur_mask] = (cur + DP[len][next][cur_mask]) % MOD;
				}
				if (digit < 9) {
					int next = digit + 1;
					int cur_mask = mask | (1 << next);
					DP[len][next][cur_mask] = (cur + DP[len][next][cur_mask]) % MOD;
				}
			}
		}
	}

	for (int i = 0; i <= 9; ++i) {
		answer = (answer + DP[N][i][MAX]) % MOD;
	}

	std::cout << answer;
	return 0;
}