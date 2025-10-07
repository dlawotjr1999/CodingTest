#include <iostream>
#include <vector>
#include <unordered_map>

// �Ʒ� ������ ����
// https://www.acmicpc.net/problem/9017

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int N;
		std::cin >> N;

		std::unordered_map<int, int> map;	// �� �� �ο��� ����
		std::vector<int> grades;			// ��ü ����� ����
		for (int i = 0; i < N; ++i) {
			int team; std::cin >> team;
			map[team]++;
			grades.emplace_back(team);
		}
		
		std::vector<int> scores[201];	// �� �� ���� ����

		// ��ü ���(grades)�� ���ؼ� Ư�� ���� �ش��ϴ� ��ġ�� ��� ����
		// ��������� scores���� �� ���� �ش��ϴ� �������� �����
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
			// 4������� ���� ����
			for (int j = 0; j < 4; ++j)
				temp += scores[i][j];
			
			// ���� ������ �۾ƾ� ������� �� �� ����
			// ���� ����� ������ ������� ������ �ε���, 5���� �ο��� ������ �����
			if (temp < winner_score) {
				winner_score = temp;
				winner = i;
				five_score = scores[i][4];
			}

			// ������ ������ ������� ������ ���� ������� ������ ���� ��� �� ���� �ټ� ��°�� ���� �ο��� ���� ������� ����
			if (temp == winner_score && five_score > scores[i][4]) {
				winner = i;
				five_score = scores[i][4];
			}
		}

		std::cout << winner << '\n';
	}

	return 0;
}