#include <bits/stdc++.h>

// �� ���� ���� a,b,c�� �־��� ��, ���� ���ǵ��� �����ϴ� ������ (x,y,z)�� ������ ���ϴ� ����
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

		// ���� : https://movegreen.tistory.com/48
		// ���ǵ��� �����ϴ� �������� x = y = z�϶��� ������
		// �׷��Ƿ� x, y, z �� ���� ���� ���� ������ŭ�� �������� ������
		int min = std::min({ a, b, c });
		std::cout << min << '\n';
	}

	return 0;
}