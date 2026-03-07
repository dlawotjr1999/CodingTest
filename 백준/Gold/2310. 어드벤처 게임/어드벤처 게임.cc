#include <bits/stdc++.h>

struct info {
	char member = 'E';
	int cost = 0;
	std::vector<int> next_rooms;
};

bool BFS(info rooms[], int goal) {
	std::vector<int> best(goal + 1, -1);
	std::queue<int> q;

	int money = 0;
	if (rooms[1].member == 'L') {
		money = std::max(money, rooms[1].cost);
	}
	else if (rooms[1].member == 'T') {
		if (money < rooms[1].cost)
			return false;
		money -= rooms[1].cost;
	}

	best[1] = money;
	q.push(1);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		int cur_money = best[cur];

		if (cur == goal)
			return true;

		for (int next : rooms[cur].next_rooms) {
			int next_money = cur_money;

			if (rooms[next].member == 'L') {
				next_money = std::max(next_money, rooms[next].cost);
			}
			else if (rooms[next].member == 'T') {
				if (next_money < rooms[next].cost)
					continue;
				next_money -= rooms[next].cost;
			}

			if (next_money > best[next]) {
				best[next] = next_money;
				q.push(next);
			}
		}
	}

	return false;
}

int main() {
	while (true) {
		int T; std::cin >> T;

		if (T == 0)
			return 0;

		info rooms[1001];

		for (int i = 1; i <= T; ++i) {
			char c; std::cin >> c; rooms[i].member = c;
			int cost; std::cin >> cost; rooms[i].cost = cost;

			while (true) { 
				int next;  std::cin >> next; 
				if (next == 0) break; 
				rooms[i].next_rooms.push_back(next);
			}
		}

		std::cout << (BFS(rooms, T) ? "Yes" : "No") << '\n';
	}
}