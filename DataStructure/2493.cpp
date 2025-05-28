#include <iostream>
#include <vector>
#include <stack>

// 일렬로 세워진 탑들이 왼쪽 방향으로 레이저를 발사할 때, 송신한 레이저 신호가 어느 탑에서 수신했는지 구하는 문제
// 송신된 레이저는 가장 먼저 만나는 탑에서 수신이 가능함
// 하나의 탑은 보다 높이가 낮은 탑에서 송신한 레이저만을 수신할 수 있음

int main() {
	int N;
	std::cin >> N;

	std::stack<std::pair<int, int>> s;
	std::vector<int> answer(N + 1);

	for (int i = 1; i <= N; i++) {
		int height;
		std::cin >> height;

		// 현재 탑에서 송신한 레이저를 수신할 수 있는 탑이 존재하는 지 확인함
		// 스택의 top이 현재 탑의 높이보다 낮은 경우에는 레이저를 수신할 수 없으므로 pop을 진행
		while (!s.empty() && s.top().second < height) {
			s.pop();
		}
		// 스택이 비어있으면, 즉 현재 탑에서 송신한 레이저를 받을 탑이 없는 경우에는 0을 출력
		// 그렇지 않으면, 즉 송신한 레이저를 받을 탑이 있으면 수신한 탑의 index를 출력
		answer[i] = s.empty() ? 0 : s.top().first;
		s.emplace(i, height);
	}

	for (int i = 1; i <= N; i++) 
		std::cout << answer[i] << ' ';
	return 0;
}