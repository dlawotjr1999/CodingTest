#include <bits/stdc++.h>

// 다음 문제를 구현
// https://www.acmicpc.net/problem/20125

const int MAX = 1001;

int N;
char field[MAX][MAX];

int heart_y, heart_x;
int left_arm, right_arm, waist, left_leg, right_leg;

int main() {
	std::cin >> N;

	// 팔이 위치한 행, 머리(심장)이 위치한 열, 전체 팔의 길이
	int arm_row = 0; int head_col = 0;
	int arm_length = 0;

	// find the heart pos
	// 가장 긴 *문자열이 위치한 행이 팔이 위치한 행
	for (int i = 1; i <= N; ++i) {
		int cnt = 0;

		for (int j = 1; j <= N; ++j) {
			std::cin >> field[i][j];

			if (field[i][j] == '*')
				cnt++;
		}
		if (arm_length <= cnt) {
			arm_length = cnt;
			arm_row = i;
		}
	}

	// 팔이 위치한 행의 바로 윗칸이 *인 경우가 머리(심장)이 위치한 열
	// 즉, (팔이 위치한 행, 머리가 위치한 열)이 심장이 위치한 좌표
	for (int j = 1; j <= N; ++j) {
		if (field[arm_row - 1][j] == '*')
			head_col = j;
	}
	heart_y = arm_row, heart_x = head_col;

	// get the length of each arm
	// 심장이 위치한 열을 기준으로 왼쪽 팔의 길이와 오른쪽 팔의 길이를 구함
	for (int i = 1; i <= N; ++i) {
		if (field[arm_row][i] == '*' && i < head_col)
			left_arm++;
		else if (field[arm_row][i] == '*' && i > head_col)
			right_arm++;
	}

	// get the length waist
	// 머리가 위치한 열에서, 팔이 위치한 행의 바로 아래 행부터 *의 길이가 허리의 길이
	for (int i = (arm_row + 1); i <= N; ++i) {
		if (field[i][head_col] == '*')
			waist++;
	}

	// get the length of each leg
	// (팔이 위치한 행 + 허리의 길이 + 1)이 다리가 시작하는 위치
	int leg_start = arm_row + waist + 1;

	// 허리가 위치한 열을 기준으로 왼쪽 다리와 오른쪽 다리의 길이를 구함
	for (int i = leg_start; i <= N; ++i) {
		if (field[i][head_col - 1] == '*')
			left_leg++;
		if (field[i][head_col + 1] == '*')
			right_leg++;
	}
	
	std::cout << heart_y << ' ' << heart_x << '\n';
	std::cout << left_arm << ' ' << right_arm << ' ' << waist<< ' ' << left_leg << ' ' << right_leg;

	return 0;
}