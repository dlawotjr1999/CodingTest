#include <iostream> 
#include <vector>

int main() {
	int N;
	std::cin >> N;

	std::vector<long long> DP(N + 1);
	DP[0] = 0; DP[1] = 1; DP[2] = 2;

	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 2] + DP[i - 1]) % 10007;
	}
	std::cout << DP[N];

	return 0;
}