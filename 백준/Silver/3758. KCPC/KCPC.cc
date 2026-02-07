#include <bits/stdc++.h>

// 팀 번호, 누적 점수, 누적 시도, 제출 시간 , 푼 문제들
struct info {
	int team = 0;
	int score = 0;
	int attempt = 0;
	int last = 0;
	std::vector<int> best;
};

int main() {
	int T; std::cin >> T;

	while (T--) {
		int n, k, t, m;
		std::cin >> n >> k >> t >> m;

		int seq = 1;
		std::vector<info> vec(n + 1);

		for (int i = 1; i <= n; ++i) {
			vec[i].team = i;
			vec[i].best.assign(k + 1, 0);
		}

		while (m--) {
			int i, j, s;
			std::cin >> i >> j >> s;

			vec[i].attempt++;
			vec[i].last = seq++;
			
			if (vec[i].best[j] < s) {
				vec[i].score += (s - vec[i].best[j]);
				vec[i].best[j] = s;
			}
		}

		std::sort(vec.begin() + 1, vec.end(), [](const auto& l, const auto& r) {
			if (l.score != r.score)
				return l.score > r.score;
			if (l.attempt != r.attempt)
				return l.attempt < r.attempt;
			return l.last < r.last;
		});

		for (int idx = 1; idx <= n; ++idx) {
			if (vec[idx].team == t) {
				std::cout << idx << '\n';
				break;
			}
		}
	}
	return 0;
}