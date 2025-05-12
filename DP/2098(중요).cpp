#include <iostream>
#include <cstring>

// 외판원 순회 문제
// https://ko.wikipedia.org/wiki/%EC%99%B8%ED%8C%90%EC%9B%90_%EB%AC%B8%EC%A0%9C

constexpr int MAX = 16;
constexpr int INF = 1e9;

int N;
int full_bit;

int matrix[MAX][MAX];
int DP[MAX][1 << MAX];

int DFS(int cur_node, int cur_bit) {
	if (cur_bit == full_bit) {
		if (matrix[cur_node][0] != 0)
			return matrix[cur_node][0];
		return INF;
	}

	int& ret = DP[cur_node][cur_bit];
	if (ret != -1) 
		return ret;

	ret = INF;
	for (int i = 0; i < N; i++) {
		int cost = matrix[cur_node][i];
		if (cur_bit & (1 << i) || cost == 0)
			continue;
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