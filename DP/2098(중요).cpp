#include <iostream>
#include <cstring>

// 외판원 순회 문제
// https://ko.wikipedia.org/wiki/%EC%99%B8%ED%8C%90%EC%9B%90_%EB%AC%B8%EC%A0%9C

constexpr int MAX = 16;
constexpr int INF = 1e9;

int N;
int full_bit;

int matrix[MAX][MAX];

// 현재 노드 번호와 이제까지의 방문 상태를 저장하는 테이블
// e.g. DP[2][0b01101] : 도시 2에 있으며, { 0,2,3 }번 도시를 이미 방문했을 때, 나머지 도시를 모두 방문하고 0번으로 돌아오는 최소 비용
int DP[MAX][1 << MAX];

int DFS(int cur_node, int cur_bit) {
	// 모든 노드를 방문한 상태이며, 현재 노드에서 0번으로 가는 경로가 있으면 최소 비용 반환
	// 불가능한 경우에는 INF 반환
	if (cur_bit == full_bit) {
		if (matrix[cur_node][0] != 0)
			return matrix[cur_node][0];
		return INF;
	}

	// 이미 계산된 값이 있으면 곧바로 반환하여 중복을 피함
	int& ret = DP[cur_node][cur_bit];
	if (ret != -1) 
		return ret;

	ret = INF;
	for (int i = 0; i < N; i++) {
		int cost = matrix[cur_node][i];

		// cur_bit에 i번 비트가 1이거나(즉 i번 노드를 방문했거나), cost가 0일 때(즉 간선이 없을 때)는 건너뜀
		if (cur_bit & (1 << i) || cost == 0)
			continue;

		// 방문할 노드 중 최소비용을 가진 경로로 이동함
		ret = std::min(ret, DFS(i, cur_bit | (1 << i)) + cost);
	}
	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> matrix[i][j];
		}
	}
	full_bit = (1 << N) - 1;

	memset(DP, -1, sizeof(DP));
	std::cout << DFS(0, 1);

	return 0;
}