#include <iostream>
#include <deque>

// deque 활용 문제
// 풍선을 터뜨리면 내부의 숫자만큼 이동해서 풍선이 터지는 순서를 구하는 문제

int main() {
	int N;
	std::cin >> N;

	// 풍선에 적힌 숫자와 순서를 한 번에 관리하기 위해 pair를 사용
	std::deque<std::pair<int, int>> ballons;

	for (int i = 1; i <= N; i++) {
		int num;
		std::cin >> num;

		ballons.emplace_back(num, i);
	}

	while (!ballons.empty()) {

		// 맨 앞의 풍선을 터뜨린다
		// 터뜨린 풍선은 deque에서 뺀다
		int num = ballons.front().first;
		std::cout << ballons.front().second << " ";
		ballons.pop_front();

		// 풍선을 '터뜨리고' 안에 있는 숫자만큼 이동을 한다
		// '터뜨린다' 라는 것은 front 포인터를 알맞은 위치에 배치하는 것
		// NOTE : 양수는 터뜨리고 난 후 이동을, 음수는 이동 후 터뜨리기를 진행해야 함
		if (num > 0) {
			for (int i = 0; i < (num - 1); i++) {
				ballons.push_back(ballons.front());
				ballons.pop_front();
			}
		}
		else {
			for (int i = num; i < 0; i++) {
				ballons.push_front(ballons.back());
				ballons.pop_back();
			}
		}

	}
	return 0;
}