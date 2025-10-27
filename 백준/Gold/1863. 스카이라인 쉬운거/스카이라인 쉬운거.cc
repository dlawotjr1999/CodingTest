#include <bits/stdc++.h>

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

		while (!s.empty() && cur < s.top()) {
			answer++;
			s.pop();
		}
		if (!s.empty() && s.top() == cur)
			continue;
		s.push(cur);
	}

	while (!s.empty()) {
		if (s.top() > 0)
			answer++;
		s.pop();
	}

	std::cout << answer;
	return 0;
}