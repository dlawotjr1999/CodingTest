#include <iostream>
#include <vector>
#include <unordered_map>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/9017

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int N;
		std::cin >> N;

		std::unordered_map<int, int> map;	// 팀 당 인원수 저장
		std::vector<int> grades;			// 전체 등수를 저장
		for (int i = 0; i < N; ++i) {
			int team; std::cin >> team;
			map[team]++;
			grades.emplace_back(team);
		}
		
		std::vector<int> scores[201];	// 팀 별 점수 저장

		// 전체 등수(grades)를 통해서 특정 팀에 해당하는 위치에 등수 삽입
		// 결과적으로 scores에는 각 팀에 해당하는 점수들이 저장됨
		int idx = 0;
		for (int i = 0; i < N; ++i) {
			if (map[grades[i]] == 6) {
				scores[grades[i]].push_back(idx + 1);
				idx++;
			}
		}

		int winner = -1;
		int five_score = -1;
		int winner_score = 100000;

		for (int i = 1; i <= 200; ++i) {
			int temp = 0;

			if (scores[i].size() < 6)
				continue;
			// 4등까지의 점수 누적
			for (int j = 0; j < 4; ++j)
				temp += scores[i][j];
			
			// 누적 점수가 작아야 우승팀이 될 수 있음
			// 연산 결과로 구해진 우승팀의 점수와 인덱스, 5등인 인원의 점수를 기록함
			if (temp < winner_score) {
				winner_score = temp;
				winner = i;
				five_score = scores[i][4];
			}

			// 이전에 구해진 우승팀의 점수와 현재 우승팀의 점수가 같을 경우 더 빨리 다섯 번째로 들어온 인원을 통해 우승팀을 가림
			if (temp == winner_score && five_score > scores[i][4]) {
				winner = i;
				five_score = scores[i][4];
			}
		}

		std::cout << winner << '\n';
	}

	return 0;
}