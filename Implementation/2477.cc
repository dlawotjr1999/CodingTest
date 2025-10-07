#include <iostream>
#include <vector>
#include <cstring>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/2477

int answer;

int main() {
	int N;
	std::cin >> N;

	int width = 1;
	int deleted_width = 1;

	std::vector<std::pair<int, int>> vec;

	// 각 방향들이 등장한 횟수를 저장
	int dir_cnt[4];
	memset(dir_cnt, 0, sizeof(dir_cnt));

	for (int i = 0; i < 6; ++i) {
		int dir, len;
		std::cin >> dir >> len;

		vec.emplace_back(dir, len);
		dir_cnt[dir - 1]++;
	}

	for (int i = 0; i < 6; ++i) {
		// 큰 직사각형의 넓이는 한 번만 등장한 방향 두 개의 길이의 곱과 같음
		if (dir_cnt[vec[i].first - 1] == 1) {
			width *= vec[i].second;
			continue;
		}

		// 작은 직사각형의 넓이를 이루는 두 길이는 같은 방향 사이에 등장하는 길이로 구성됨
		// 예를 들어 2 1 2, 1 2 1로 패턴이 등장할 경우 작은 사각형의 넓이는 1과 2의 곱으로 구할 수 있음
		if (vec[i % 6].first == vec[(i + 2) % 6].first) {
			deleted_width *= vec[(i + 1) % 6].second;
		}
	}

	// 큰 사각형에서 작은 사각형의 면적을 뺀 뒤, 면적 당 재배 가능한 참외의 수를 곱하면 답을 구할 수 있음
	width -= deleted_width;
	answer = N * width;

	std::cout << answer;
	return 0;
}