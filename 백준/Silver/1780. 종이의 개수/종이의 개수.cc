#include <bits/stdc++.h>

int ans1, ans2, ans3;
std::vector<std::vector<int>> field;

void CheckPaper(int x, int y, int n) {
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
		if (base == -1)
			ans1++;
		else if (base == 0)
			ans2++;
		else if (base == 1)
			ans3++;
		return;
	}
	else {
		int size = n / 3;

		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				CheckPaper(x + j*size, y + i*size, n/3);
			}
		}
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

	CheckPaper(0, 0, N);

	std::cout << ans1 << '\n' << ans2 << '\n' << ans3;
	return 0;
}