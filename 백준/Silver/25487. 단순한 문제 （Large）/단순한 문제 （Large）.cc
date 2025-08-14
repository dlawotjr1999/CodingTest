#include <bits/stdc++.h>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {
		int a, b, c;
		std::cin >> a >> b >> c;

		int min = std::min({ a, b, c });
		std::cout << min << '\n';
	}

	return 0;
}