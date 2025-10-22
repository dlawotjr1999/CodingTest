#include <bits/stdc++.h>

const int MAX = 1001;

int N;
char field[MAX][MAX];

int heart_y, heart_x;
int left_arm, right_arm, waist, left_leg, right_leg;

int main() {
	std::cin >> N;

	int arm_row = 0; int head_col = 0;
	int arm_length = 0;

	// find the heart pos
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

	for (int j = 1; j <= N; ++j) {
		if (field[arm_row - 1][j] == '*')
			head_col = j;
	}
	heart_y = arm_row, heart_x = head_col;

	// get the length of each arm
	for (int i = 1; i <= N; ++i) {
		if (field[arm_row][i] == '*' && i < head_col)
			left_arm++;
		else if (field[arm_row][i] == '*' && i > head_col)
			right_arm++;
	}

	// get the length waist
	for (int i = (arm_row + 1); i <= N; ++i) {
		if (field[i][head_col] == '*')
			waist++;
	}

	// get the length of each leg
	int leg_start = arm_row + waist + 1;

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