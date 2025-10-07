#include <iostream>
#include <deque>

// N장의 카드가 있을 때 다음의 동작을 반복한다고 하자
// 제일 위에 있는 카드를 바닥에 버리고 그 다음, 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮김
// 위 동작을 카드가 한 장이 남을 때까지 반복한다고 할 때 가장 마지막에 남는 카드를 구하는 문제

int main() {
	int N;	std::cin >> N;
	std::deque<int> dq;

	for (int i = 1; i <= N; ++i) {
		dq.push_back(i);
	}

	// 카드가 한 장이 남을 때까지 반복
	while (dq.size() > 1) {
		// 가장 위에 있는 카드를 버리고, 그 다음 가장 위에 있는 카드를 제일 아래의 카드 밑으로 옮김
		dq.pop_front();

		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}

	// 가장 마지막에 남은 카드 출력
	std::cout << dq.back();
	return 0;
}