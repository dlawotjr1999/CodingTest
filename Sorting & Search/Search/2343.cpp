#include <iostream>
#include <vector>

int N, M;
std::vector<int> vec;

int start = 0;
int end = 0;

int main() {
	std::cin >> N >> M;
	vec.resize(N);

	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];

		if (start < vec[i])
			start = vec[i];
		end += vec[i];
	}

	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = 0;
		int cnt = 0;

		for (int i = 0; i < N; i++) {
			if (sum + vec[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += vec[i];
		}
		if (sum != 0)
			cnt++;
		if (cnt > M)
			start = mid + 1;
		else
			end = mid - 1;
	}

	std::cout << start;
	return 0;
}