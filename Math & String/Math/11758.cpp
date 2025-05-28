#include <iostream>

// CCW 알고리즘 구현
// CCW 알고리즘에서 연산 결과의 부호값에 따라 점들의 위치 관계는 아래와 같음
// 1. 음수인 경우 : 점들이 시계 방향으로 구성됨
// 2. 0인 경우 : 점들이 일직선 상에 있음
// 3. 양수인 경우 : 점들이 반시계 방향으로 구성됨

int main() {
	int x1, y1, x2, y2, x3, y3;
	std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

	int result = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);

	if (result < 0)
		std::cout << -1;
	else if (result == 0)
		std::cout << 0;
	else
		std::cout << 1;

	return 0;
}