#include <iostream>
#include <vector>
#include <unordered_map>

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int N;
		std::cin >> N;

		std::unordered_map<int, int> map;
		std::vector<int> grades;
		for (int i = 0; i < N; ++i) {
			int team; std::cin >> team;
			map[team]++;
			grades.emplace_back(team);
		}
		
		std::vector<int> scores[201];

		int idx = 1;
		for (int i = 0; i < N; ++i) {
			if (map[grades[i]] == 6) {
				scores[grades[i]].push_back(idx + 1);
				idx++;
			}
		}

		int winner = -1;
		int five_idx = -1;
		int winner_score = 100000;

		for (int i = 1; i <= 200; ++i) {
			int temp = 0;

			if (scores[i].size() < 6)
				continue;
			for (int j = 0; j < 4; ++j)
				temp += scores[i][j];
			
			if (temp < winner_score) {
				winner_score = temp;
				winner = i;
				five_idx = scores[i][4];
			}

			if (temp == winner_score && five_idx > scores[i][4]) {
				winner = i;
				five_idx = scores[i][4];
			}
		}

		std::cout << winner << '\n';
	}

	return 0;
}