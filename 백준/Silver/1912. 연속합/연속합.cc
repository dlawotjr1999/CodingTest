#include <iostream>
#include <vector>

int DP[100001];
int answer;

int main() {
	int n;
	std::cin >> n;

	std::vector<int> vec(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> vec[i];
		DP[i] = vec[i];
	}
	answer = vec[1];

	for (int i = 2; i <= n; ++i) {
		DP[i] = std::max(DP[i - 1] + vec[i], vec[i]);
		answer = std::max(answer, DP[i]);
	}

	std::cout << answer;
	return 0;
}