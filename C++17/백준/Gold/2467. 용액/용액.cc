#include <iostream>
#include <vector>
#include <climits>

typedef long long ll;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<ll> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	long long l = 0, r = N - 1;

	long long answer = LLONG_MAX;
	long long x = vec[l], y = vec[r];

	while (l < r) {
		long long ph = vec[l] + vec[r];

		if (llabs(ph) < answer) {
			answer = llabs(ph);
			x = vec[l];
			y = vec[r];
		}

		if (ph < 0)
			l++;
		else if (ph > 0)
			r--;
		else
			break;
	}

	std::cout << x << ' ' << y;
	return 0;
}
