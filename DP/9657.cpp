#include <iostream>
#include <vector>
#define MAX 1001

int dp[MAX];

int main() {
	int n;
	std::cin >> n;

	dp[0] = 0;
	dp[1] = 0;
	dp[2] = 1;
	dp[3] = 0;
	dp[4] = 1;

	for (int i = 5; i <= n; i++) {
		if (dp[i - 4] == 0 || dp[i - 3] == 0 || dp[i - 1] == 0)
			dp[i] = 1;
		else
			dp[i] = 0;
	}

	if (dp[n])
		std::cout << "SK";
	else
		std::cout << "CY";

	return 0;
}