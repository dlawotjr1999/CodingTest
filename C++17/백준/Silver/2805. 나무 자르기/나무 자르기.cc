#include <iostream>
#include <vector>

int answer;

int main() {
	int N, M;
	std::cin >> N >> M;

	int l = 0,  r = 0;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
		r = std::max(r, vec[i]);
	}

	while (l <= r) {
		int mid = (l + r) / 2;

		long long len = 0;
		for (int elm : vec) {
			if (elm >= mid)
				len += (elm - mid);
		}

		if (M <= len) {
			answer = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}

	std::cout << answer;
	return 0;
}