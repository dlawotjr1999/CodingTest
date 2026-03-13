#include <bits/stdc++.h>

int main() {
	int T; std::cin >> T;
	
	while (T--) {
		int N; std::cin >> N;
		int answer = -1;

		std::vector<int> logs(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> logs[i];
		}
		std::sort(logs.begin(), logs.end());

		std::deque<int> dq;
		dq.push_back(logs.back());

		int l = N - 3, r = N - 2;
		int temp_l = 0, temp_r = 0;

		while (0 <= l && 0 <= r) {
			temp_l = std::abs(dq.front() - logs[l]);
			temp_r = std::abs(dq.back() - logs[r]);
			answer = std::max({ answer, temp_l, temp_r });

			dq.push_front(logs[l]); dq.push_back(logs[r]);
			l -= 2; r -= 2;
		}
		if (r == 0) {
			int old_back = dq.back();
			dq.push_back(logs[r]);

			int last_l = std::abs(dq.front() - dq.back());
			int last_r = std::abs(old_back - dq.back());
			answer = std::max({ answer, last_l, last_r });
		}
		
		std::cout << answer << '\n';
	}	

	return 0;
}