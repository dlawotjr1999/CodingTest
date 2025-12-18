#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int T;	std::cin >> T;

	while (T--) {
		int	N;	std::cin >> N;
		int answer = 1;

		std::vector<std::pair<int, int>> vec(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> vec[i].first >> vec[i].second;
		}
		std::sort(vec.begin(), vec.end());
	
		int top = vec[0].second;
		for (int i = 1; i < N; ++i) {
			if (vec[i].second < top) {
				answer++;
				top = vec[i].second;
			}
		}
		std::cout << answer << '\n';
	}

	return 0;
}