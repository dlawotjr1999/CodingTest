#include <bits/stdc++.h>

// 스카이라인의 높이들이 주어질 때, 건물이 최소 몇 채인지 구하는 문제

int answer;

int main() {
	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> skyline;
	std::stack<int> s;

	for (int i = 0; i < N; ++i) {
		int x, y;
		std::cin >> x >> y;
		skyline.emplace_back(x, y);
	}

	for (int i = 0; i < N; ++i) {
		int cur = skyline[i].second;

		// 현재 높이보다 더 큰 높이들이 스택에 있으면, 그 높이 구간은 여기서 종료된 것이므로 건물 블록 수 증가
		while (!s.empty() && cur < s.top()) {
			answer++;
			s.pop();
		}

		// 같은 높이가 연속되면 새로운 건물이 아님
		if (!s.empty() && s.top() == cur)
			continue;

		// 더 큰 높이가 들어오거나 동일 높이도 아닌 경우에는 새로운 블록 시작
		s.push(cur);
	}

	// 마지막까지 이어진 높이 블록들을 확인
	while (!s.empty()) {
		if (s.top() > 0)
			answer++;
		s.pop();
	}

	std::cout << answer;
	return 0;
}