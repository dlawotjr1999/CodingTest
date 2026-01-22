#include <bits/stdc++.h>

int cnt[200001];

int main() {
	int N, K;
	std::cin >> N >> K;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	std::deque<int> dq;
	int answer = 0;

	for (int i = 0; i < N; ++i) {
		dq.push_back(vec[i]);
		cnt[vec[i]]++;

		while (cnt[vec[i]] > K) {
			cnt[dq.front()]--;
			dq.pop_front();
		}

		answer = std::max(answer, (int)dq.size());
	}

	std::cout << answer;
	return 0;
}