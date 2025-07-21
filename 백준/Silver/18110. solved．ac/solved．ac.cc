#include <bits/stdc++.h>

int main() {
	int n;
	std::cin >> n;

	if (n == 0) {
		std::cout << 0;
		return 0;
	}

	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());
	int except = round(double(n * 3) / 20);

	double sum = 0;
	for (int i = except; i < n - except; ++i) {
		sum += vec[i];
	}

	double avg = round(sum / (n - 2 * except));

	std::cout << std::fixed << std::setprecision(0) << avg;
	return 0;
}