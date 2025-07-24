#include <bits/stdc++.h>

double answer;

int main() {
	int N;
	std::cin >> N;

	std::vector<double> beverages(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> beverages[i];
	}

	std::sort(beverages.begin(), beverages.end());
	answer = beverages[N - 1];

	for (int i = 0; i < N - 1; ++i) {
		beverages[i] /= 2;
		answer += beverages[i];
	}

	answer = round(answer * 10e5) / 10e5;
	std::cout << answer;
}