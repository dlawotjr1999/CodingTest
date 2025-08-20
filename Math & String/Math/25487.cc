#include <bits/stdc++.h>

// 세 양의 정수 a,b,c가 주어질 때, 다음 조건들을 만족하는 순서쌍 (x,y,z)의 갯수를 구하는 문제
// 1 <= x <= a, 1 <= y <= b, 1 <= z <= c
// (x % y) = (y % z) = (z % x)

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T;
	std::cin >> T;

	while (T--) {
		int a, b, c;
		std::cin >> a >> b >> c;

		// 참고 : https://movegreen.tistory.com/48
		// 조건들을 만족하는 순서쌍은 x = y = z일때만 성립함
		// 그러므로 x, y, z 중 가장 작은 값의 갯수만큼의 순서쌍이 존재함
		int min = std::min({ a, b, c });
		std::cout << min << '\n';
	}

	return 0;
}