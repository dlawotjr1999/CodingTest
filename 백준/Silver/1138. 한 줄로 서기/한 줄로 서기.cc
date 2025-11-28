#include <bits/stdc++.h>

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	std::vector<int> answer(N, 0);
	for (int i = 0; i < N; ++i) {
		int cnt = vec[i];
		
		for (int j = 0; j < N; ++j) {
			if (answer[j] == 0) {
				if (cnt == 0) {
					answer[j] = i + 1;
					break;
				}
				cnt--;
			}
		}
	}

	for (int a : answer)
		std::cout << a << ' ';
	return 0;
}