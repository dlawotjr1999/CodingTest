#include <bits/stdc++.h>

int main() {
	int N, H, T;
	std::cin >> N >> H >> T;

	std::priority_queue<int> pq;
	for (int i = 0; i < N; ++i) {
		int h; std::cin >> h;
		pq.push(h);
	}

	int time = 0;
	while (true) {
		int h = pq.top();
		pq.pop();

		if (h < H && time <= T) {
			std::cout << "YES\n";
			std::cout << time;
			return 0;
		}

		else if (time >= T && h >= H) {
			std::cout << "NO\n";
			std::cout << h;
			return 0;
		}

		if(h > 1) h /= 2;
		pq.push(h);

		time++;
	}
}