#include <bits/stdc++.h>

int DP[21][21][21];

int W(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0)
		return 1;

	else if (a > 20 || b > 20 || c > 20)
		return W(20, 20, 20);

	else if (DP[a][b][c] != 0)
		return DP[a][b][c];

	else if (a < b && b < c)
		return DP[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);

	else
		return DP[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
}

int main() {
	while (true) {
		int a, b, c;
		std::cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1)
			break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, W(a, b, c));
	}

	return 0;
}