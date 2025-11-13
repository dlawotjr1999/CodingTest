#include <iostream>
#include <vector>
#include <algorithm>

// 다음 문제를 구현
// https://www.acmicpc.net/problem/20006

// 기준 레벨과, 기준 레벨로 이루어진 방에 입장할 수 있는 플레이어들을 저장하는 벡터로 이루어진 구조체 선언
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

		// 기존에 있는 모든 방을 순회하며, 기준 레벨에 부합하는 방이 있을 경우 입장
		bool join = false;
		for (auto& room : rooms) {
			if (room.players.size() < m && l >= room.base - 10 && l <= room.base + 10) {
				room.players.push_back({ l, n });
				join = true;
				break;
			}
		}

		// 현재 플레이어가 기존에 있는 방에 들어갈 수 없는 경우 새로운 방 생성
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

		// 이름 순서대로 출력
		std::sort(room.players.begin(), room.players.end(), [](const auto& l, const auto& r) {
			return l.second < r.second;
		});

		for (auto& [l, n] : room.players) {
			std::cout << l << ' ' << n << '\n';
		}
	}

	return 0;
}