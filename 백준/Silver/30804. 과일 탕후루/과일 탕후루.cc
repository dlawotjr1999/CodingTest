#include <bits/stdc++.h>

int answer;

int main() {
	int N;	std::cin >> N;
	int types = 0;

	std::deque<int> fruits;
	int cnt[10];
	memset(cnt, 0, sizeof(cnt));
	
	for (int i = 0; i < N; ++i) {
		int f;	std::cin >> f;
		fruits.push_back(f);

		if (cnt[f] == 0) 
			types++;
		cnt[f]++;

		while (types > 2) {
			int front = fruits.front();
			fruits.pop_front();
			cnt[front]--;

			if (cnt[front] == 0)
				types--;
		}

		answer = std::max(answer, (int)fruits.size());
	}

	std::cout << answer;
	return 0;
}