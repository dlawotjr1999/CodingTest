#include <bits/stdc++.h>

std::vector<int> answer;

int BinarySearch(int k) {
	int l = 0, r = answer.size() - 1;

	while (l < r) {
		int mid = l + (r - l) / 2;

		if (answer[mid] >= k)
			r = mid;
		else l = mid + 1;
	}

	return r;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	answer.push_back(vec.front());

	for (int i = 1; i < N; i++) {
		if (vec[i] > answer.back())
			answer.push_back(vec[i]);
		else {
			int idx = BinarySearch(vec[i]);
			answer[idx] = vec[i];
		}
	}

	std::cout << answer.size();
	return 0;
}