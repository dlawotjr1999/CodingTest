#include <bits/stdc++.h>

// 좌표 (x, y)들이 N개 주어질 때, 그 좌표들이 이루는 다각형의 면적을 구하는 문제
// 참고 : 신발끈 공식(https://ko.wikipedia.org/wiki/%EC%8B%A0%EB%B0%9C%EB%81%88_%EA%B3%B5%EC%8B%9D)

double answer;

int main() {
	int N; std::cin >> N;

	std::vector<std::pair<int, int>> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i].first >> vec[i].second;
	}

	long long sum1 = 0;
	long long sum2 = 0;
	for (int i = 0; i < N - 1; ++i) {
		sum1 += (1LL * vec[i].first * vec[i + 1].second);
		sum2 += (1LL * vec[i].second * vec[i + 1].first);
	}
	sum1 += (1LL * vec[N - 1].first * vec[0].second);
	sum2 += (1LL * vec[N - 1].second * vec[0].first);

	answer = std::llabs(sum1 - sum2) / 2.0;

	// 소수점 둘째 자리에서 반올림
	std::cout << std::fixed << std::setprecision(1) << answer;
	return 0;
}