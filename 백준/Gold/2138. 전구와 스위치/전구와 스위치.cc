#include <bits/stdc++.h>

int N;

std::string lamps1;
std::string lamps2;

int Switching(std::string cur, bool isFirst) {
	int cnt = 0;

	if (isFirst) {
		cur[0] = (cur[0] == '0' ? '1' : '0');
		if(N > 1)
			cur[1] = (cur[1] == '0' ? '1' : '0');

		cnt++;
	}

	for (int i = 1; i < N; ++i) {
		if (cur[i - 1] != lamps2[i - 1]) {
			for (int s : {i - 1, i, i + 1}) {
				if (s < 0 || s >= N)
					continue;
				cur[s] = (cur[s] == '0' ? '1' : '0');
			}
			cnt++;
		}
	}

	if (cur == lamps2)
		return cnt;
	return INT_MAX;
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		char c; std::cin >> c;
		lamps1.push_back(c);
	}

	for (int i = 0; i < N; ++i) {
		char c; std::cin >> c;
		lamps2.push_back(c);
	}
	
	int ans1 = Switching(lamps1, false);
	int ans2 = Switching(lamps1, true);

	int answer = std::min(ans1, ans2);
	std::cout << (answer != INT_MAX ? answer : -1);
	return 0;
}