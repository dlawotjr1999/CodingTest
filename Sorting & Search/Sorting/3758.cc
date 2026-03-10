#include <bits/stdc++.h>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/3758

// 팀 번호, 누적 점수, 누적 시도, 마지막 제출 시간, 푼 문제들
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

		// 각 팀의 정보들 초기화
		// best 벡터에는 푼 문제들의 최고 점수가 저장됨
		for (int i = 1; i <= n; ++i) {
			vec[i].team = i;
			vec[i].best.assign(k + 1, 0);
		}

		while (m--) {
			// 팀 ID, 문제 번호, 획득 점수
			int i, j, s;
			std::cin >> i >> j >> s;

			// 로그에 따라 시도횟수와 마지막 제출 시간 저장
			vec[i].attempt++;
			vec[i].last = seq++;
			
			// 이미 푼 문제를 다시 풀어서 더 높은 점수를 얻었을 경우
			// (다시 푼 점수 - 현재 점수)를 총 점수에 누적
			// 그 문제의 최고점을 갱신
			if (vec[i].best[j] < s) {
				vec[i].score += (s - vec[i].best[j]);
				vec[i].best[j] = s;
			}
		}

		std::sort(vec.begin() + 1, vec.end(), [](const auto& l, const auto& r) {
			// 최종 점수를 기준으로 정렬
			if (l.score != r.score)
				return l.score > r.score;
			// 최종 점수가 같은 경우, 풀이를 제출한 횟수가 적은 팀의 순위가 높음
			if (l.attempt != r.attempt)
				return l.attempt < r.attempt;
			// 최종 점수도 같고 제출 횟수도 같은 경우 : 마지막 제출 시간이 더 빠른 팀의 순위가 높음
			return l.last < r.last;
		});

		// t번째 팀에 대한 순위 출력
		for (int idx = 1; idx <= n; ++idx) {
			if (vec[idx].team == t) {
				std::cout << idx << '\n';
				break;
			}
		}
	}
	return 0;
}