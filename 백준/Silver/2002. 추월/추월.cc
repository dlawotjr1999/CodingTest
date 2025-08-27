#include <bits/stdc++.h>

int answer;

int main() {
	int N;
	std::cin >> N;

	std::map<std::string, int> map;
	std::vector<std::string> vec(N);

	for (int i = 0; i < N; ++i) {
		std::string str;
		std::cin >> str;
		map[str] = i;
	}

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (map[vec[i]] > map[vec[j]]) {
				answer++;
				break;
			}
		}
	}

	std::cout << answer;
	return 0;
}