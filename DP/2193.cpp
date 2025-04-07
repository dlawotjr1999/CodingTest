#include <iostream> 
#include <vector>

int main() {
	int N;
	std::cin >> N;

	std::vector<long long> DP(N + 1);
	DP[0] = 0; DP[1] = 1;

	for (int i = 2; i <= N; i++) {
		DP[i] = DP[i - 2] + DP[i - 1];
	}
	std::cout << DP[N];
	
	return 0;
}