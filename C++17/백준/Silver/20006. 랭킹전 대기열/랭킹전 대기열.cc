#include <iostream>
#include <vector>
#include <algorithm>

struct info {
	int base;
	std::vector<std::pair<int, std::string>> players;
};

int main() {
	int p, m;
	std::cin >> p >> m;

	std::vector<info> rooms;

	for (int i = 0; i < p; ++i) {
		int l; std::string n;
		std::cin >> l >> n;

		bool join = false;
		for (auto& room : rooms) {
			if (room.players.size() < m && l >= room.base - 10 && l <= room.base + 10) {
				room.players.push_back({ l, n });
				join = true;
				break;
			}
		}

		if (!join) {
			info new_room;
			new_room.base = l;
			new_room.players.push_back({ l, n });
			rooms.push_back(new_room);
		}
	}

	for (auto& room : rooms) {
		if (room.players.size() == m) 
			std::cout << "Started!" << '\n';
		else 
			std::cout << "Waiting!" << '\n';

		std::sort(room.players.begin(), room.players.end(), [](const auto& l, const auto& r) {
			return l.second < r.second;
		});

		for (auto& [l, n] : room.players) {
			std::cout << l << ' ' << n << '\n';
		}
	}

	return 0;
}