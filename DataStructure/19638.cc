#include <bits/stdc++.h>

// 마법의 뿅망치를 맞으면 키가 절반이 되며, 키가 1인 경우에는 더 줄어들 수 없음
// 마법의 뿅망치의 횟수에는 제한이 있기 때문에 효율적으로 사용하기 위해 가장 키가 큰 거인 가운데 하나를 때리기로 함
// 이 때, 뿅망치를 전략대로 이용하여 모든 거인의 키가 H보다 작도록 할 수 있는지를 구하는 문제

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

		// 최대 T번까지 진행했을 때 가장 큰 거인의 키가 H보다 작으면 OK
		if (h < H && time <= T) {
			std::cout << "YES\n";
			std::cout << time;
			return 0;
		}

		// T번 (이상)까지 진행을 해도 가장 큰 거인의 키가 H 이상인 경우엔 불가능
		else if (time >= T && h >= H) {
			std::cout << "NO\n";
			std::cout << h;
			return 0;
		}

		// 1보다 큰 키의 거인만 키를 줄일 수 있음
		if(h > 1) h /= 2;
		pq.push(h);

		// 최초 상태에서도 감별이 가능하므로 time은 모든 연산 후에 증가시킴
		time++;
	}
}