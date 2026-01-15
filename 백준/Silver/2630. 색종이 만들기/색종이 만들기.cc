#include <bits/stdc++.h>

int white_num, blue_num;
std::vector<std::vector<int>> field;

void GetPaperNum(int y, int x, int n) {
	int base = field[y][x];

	bool isOk = true;
	for (int i = y; i < y + n; ++i) {
		for (int j = x; j < x + n; ++j) {
			if (base != field[i][j]) {
				isOk = false;
				break;
			}
		}
		if (!isOk)
			break;
	}

	if (isOk) {
		if (base == 0)
			white_num++;
		else if (base == 1)
			blue_num++;
	}
	else {
		GetPaperNum(y, x, n / 2);
		GetPaperNum(y, x + n/2, n / 2);
		GetPaperNum(y + n/2, x, n / 2);
		GetPaperNum(y + n/2, x + n/2, n / 2);
	}
}

int main() {
	int N; std::cin >> N;
	field.resize(N, std::vector<int>(N));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			std::cin >> field[i][j];
		}
	}

	GetPaperNum(0, 0, N);
	std::cout << white_num << '\n' << blue_num;
	return 0;
}