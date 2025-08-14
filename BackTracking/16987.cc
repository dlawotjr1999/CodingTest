#include <bits/stdc++.h>

// 계란으로 다른 계란들을 쳐서 깨트린 후, 깨진 계란의 최대 갯수를 구하는 문제
// 계란으로 다른 계란을 치면, 각 계란의 내구도는 상대 계란의 무게만큼 깎이게 됨
// 계란들을 깨는 규칙은 아래와 같음
// 1. 가장 왼쪽의 계란을 들고 시작함
// 2. 들고 있는 계란으로 깨지지 않은 다른 계란 중에서 하나를 치며, 만약 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어감. 이후 손에 든 계란을 원래 자리에 내려놓고 3번 과정을 진행.
// 3. 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정을 다시 진행함. 단, 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료함.

int N, answer;
std::vector<std::pair<int, int>> eggs;

void DFS(int idx) {
	// 탐색이 끝난 후 egg.first 즉 계란의 내구도가 0 이하인 경우에 깨진 계란의 수를 셈
	if (idx == N) {
		int cnt = 0;

		for(auto& egg : eggs) {
			if (egg.first <= 0)
				cnt++;
		}
		answer = std::max(answer, cnt);
		return;
	}

	// 현재 계란이 깨진 경우 한 칸 오른쪽의 계란으로 넘어감
	if (eggs[idx].first <= 0) {
		DFS(idx + 1);
		return;
	}

	bool is_all_broken = true;

	// 모든 계란들을 탐색하며, 현재 계란이거나 혹은 다른 계란들의 내구도가 0인 경우(즉, 깨진 계란을 의미함)에는 넘어감
	// N개의 계란들의 내구도가 모두 0 이하라면, 모든 계란이 깨진 경우이므로 is_all_broken이 true로 유지됨
	for (int i = 0; i < N; ++i) {
		if (i == idx || eggs[i].first <= 0)
			continue;
		is_all_broken = false;

		eggs[idx].first -= eggs[i].second;
		eggs[i].first -= eggs[idx].second;

		// 가장 최근에 든 계란의 한 칸 오른쪽 계란을 치는 과정을 탐색
		DFS(idx + 1);

		eggs[idx].first += eggs[i].second;
		eggs[i].first += eggs[idx].second;
	}

	if (is_all_broken)
		DFS(idx + 1);
		// 더 정확한 표현 : DFS(N);
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int durability, weight;
		std::cin >> durability >> weight;
		eggs.emplace_back(durability, weight);
	}

	// 가장 왼쪽의 계란부터 시작
	DFS(0);

	answer = std::max(0, answer);
	std::cout << answer;

	return 0;
}