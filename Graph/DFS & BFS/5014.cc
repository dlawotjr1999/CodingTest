#include <bits/stdc++.h>

// F층으로 이루어진 건물 내에서, 현재 있는 S층에서 G층으로 이동하고자 함 
// 엘리베이터의 버튼은 위로 U층을 가는 버튼과, 아래로 S층을 가는 버튼 두 종류가 있음
// 이 때, G층에 도착하기 위해 버튼을 적어도 몇 번 누르는지 구하는 문제 

int F, S, G, U, D;

void BFS() {
	std::vector<bool> visited(F + 1, false);
	
	// (현재 층, 버튼을 누른 횟수)를 저장하는 queue 사용
	std::queue<std::pair<int, int>> q;

	q.emplace(S, 0);
	visited[S] = true;

	int answer = 0;	bool isFound = false;
	while (!q.empty()) {
		auto [cur, cnt] = q.front();
		q.pop();

		// 현재 층이 목표로 하고 있는 층(G)인 경우 도달 성공 
		if (cur == G) {
			answer = cnt;
			isFound = true;
			break;
		}

		// 현재 층에서 다음 층으로 가는 경우는 오로지 +U거나 -D
		for (int next : {cur + U, cur - D}) {

			// 다음으로 가게 되는 층이 1층 미만이거나 꼭대기(F)층보다 높은 경우에는 불가능
			if (next < 1 || next > F)
				continue;
			if (visited[next])
				continue;

			visited[next] = true;
			q.emplace(next, cnt + 1);
		}
	}

	// 도달하지 못할 경우에는 "use the stairs" 출력
	if (isFound)
		std::cout << answer;
	else
		std::cout << "use the stairs";
}

int main() {
	std::cin >> F >> S >> G >> U >> D;
	BFS();
	return 0;
}