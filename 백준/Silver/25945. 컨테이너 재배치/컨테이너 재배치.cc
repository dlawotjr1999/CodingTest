#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n; std::cin >> n;
	int sum = 0;

	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
		sum += vec[i];
	}
	std::sort(vec.begin(), vec.end());

	int avg = sum / n;
	int cnt1 = 0, cnt2 = 0;

	for (int i = 0; i < n; ++i) {
		if (vec[i] < avg) {
			cnt1 += (avg - vec[i]);
		}
		else if (vec[i] > avg + 1) {
			cnt2 += (vec[i] - avg - 1);
		}
	}
	
	std::cout << std::max(cnt1, cnt2);
	return 0;
}