#include <iostream>
#include <vector>

int DP[1001];
int answer;

int main() {
	int n;	
	std::cin >> n;

	std::vector<int> vec(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> vec[i];
		DP[i] = 1;
	}

	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (vec[j] < vec[i]) {
				DP[i] = std::max(DP[i], DP[j] + 1);
			}
		}
		answer = std::max(answer, DP[i]);
	}

	std::cout << answer;
	return 0;
}