#include <iostream>
#include <vector>
#include <climits>

const int MAX = 501;

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int K; 
		std::cin >> K;
	
		std::vector<int> vec(K + 1);
		std::vector<int> sum(K + 1, 0);
		std::vector<std::vector<int>> DP(K + 1, std::vector<int>(K + 1, 0));
		
		for (int i = 1; i <= K; ++i) {
			std::cin >> vec[i];
			sum[i] = sum[i - 1] + vec[i];
		}

		for (int gap = 1; gap < K; ++gap) {
			for (int s = 1; s + gap <= K; ++s) {
				int e = s + gap;
				DP[s][e] = INT_MAX;

				for (int m = s; m < e; ++m) {
					DP[s][e] = std::min(DP[s][e], DP[s][m] + DP[m + 1][e] + sum[e] - sum[s - 1]);
				}
			}
		}

		std::cout << DP[1][K] << '\n';
	}

	return 0;
}