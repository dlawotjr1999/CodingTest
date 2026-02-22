#include <bits/stdc++.h>

int answer = 0;

int main() {
	int N; std::cin >> N;

	std::vector<std::pair<int, bool>> mines(N);
	std::vector<std::pair<int, int>> seq(N);
	std::vector<int> answers;

	for (int i = 0; i < N; ++i) {
		int p; std::cin >> p;
		mines[i] = { p, true };
		seq[i] = { p, i };
	}
	std::sort(seq.begin(), seq.end(), std::greater<std::pair<int, int>>());

	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		if (cnt == N)
			break;

		int idx = seq[i].second;
		int l = idx - 1;

		if (!mines[idx].second)
			continue;
		mines[idx].second = false;
		cnt++;

		while (l >= 0 && mines[l].first < mines[idx].first) {
			if (!mines[l].second) break;

			mines[l].second = false;
			cnt++;
			idx = l;
			l--;
		}

		idx = seq[i].second;
		int r = idx + 1;
		while (r <= N - 1 && mines[r].first < mines[idx].first) {
			if (!mines[r].second) break;
			
			mines[r].second = false;
			cnt++;
			idx = r;
			r++;
		}

		answers.push_back(seq[i].second);
	}

	std::sort(answers.begin(), answers.end());
	for (int elm : answers)
		std::cout << elm + 1 << '\n';

	return 0;
}