#include <bits/stdc++.h>

int answer;

int main() {
	int N, K, B;
	std::cin >> N >> K >> B;

	std::vector<bool> lights(N + 1, true);

	for (int i = 0; i < B; ++i) {
		int num; std::cin >> num;
		lights[num] = false;
	}
	
	for (int i = 1; i <= K; ++i) {
		if (!lights[i])
			answer++;
	}

	int cnt = answer;
	for (int i = K + 1; i <= N; ++i) {
		if (!lights[i])
			cnt++;

		if (!lights[i - K])
			cnt--;

		answer = std::min(answer, cnt);
	}

	std::cout << answer;
	return 0;
}