#include <iostream>
#include <vector>
#include <queue>

// 일렬로 줄을 선 사람들에게 한 번에 한 조각씩만 피자를 나눠주려고 함
// 줄을 선 사람들은 한 조각을 받으면 맨 뒤로 이동하고 다시 순서가 와야 피자 조각을 받을 수 있음
// 이 때, 각 인원이 원하는만큼 피자 조각을 모두 먹으려면 얼마나 대기를 해야하는지를 구하는 문제

int main() {
	int N;
	std::cin >> N;
	
	// 줄을 구현하기 위해 큐를 사용
	// 큐는 (필요한 피자 조각 수, 인덱스)의 순서쌍을 가짐
	std::queue<std::pair<int, int>> q;
	std::vector<int> vec(N, 0);

	for (int i = 0; i < N; ++i) {
		int num;
		std::cin >> num;
		q.emplace(num, i);
	}

	// 대기 시간 변수
	int time = 0;
	while (!q.empty()) {
		// 피자를 받으면 원하는 수량 감소 및 대기 시간 증가 
		auto [piece, idx] = q.front();
		piece--;
		time++;

		q.pop();

		// 원하는 만큼 받으면 대기 시간 기록
		if (piece == 0) {
			vec[idx] = time;
		}
		// 원하는 수량이 남아있으면, 일단 받은 인원은 맨 뒤로 이동
		else {
			q.emplace(piece, idx);
		}
	}

	for (int i = 0; i < N; i++) {
		std::cout << vec[i] << ' ';
	}
	return 0;
}