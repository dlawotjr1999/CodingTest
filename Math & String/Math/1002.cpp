#include <iostream>
#include <cmath>

// 두 원의 위치 관계를 구현하는 문제
// 참고 : https://blog.naver.com/honeyeah/110140815554

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int x1, y1, r1, x2, y2, r2;
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

		int answer = 0;

		float dist = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

		if (dist == abs(r1 - r2) && dist != 0)
			answer = 1;
		else if (dist == abs(r1 + r2))
			answer = 1;
		else if (dist < abs(r1 - r2))
			answer = 0;
		else if (dist > (r1 + r2))
			answer = 0;
		else if (abs(r1 - r2) < dist && dist < (r1 + r2))
			answer = 2;
		else if (dist == 0 && r1 == r2)
			answer = -1;

		std::cout << answer << std::endl;
	}

	return 0;
}