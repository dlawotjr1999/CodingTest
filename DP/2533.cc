#include <bits/stdc++.h>

// SNS 내 친구 관계의 그래프가 트리의 형태로 표현되어 있음
// 어떤 새로운 아이디어를 먼저 받아들인 사람을 얼리 아답터라고 하며, 사회망 서비스에 속한 사람들은 얼리 아답터이거나 얼리 아답터가 아남 
// 얼리 아답터가 아닌 사람들은 자신의 모든 친구들이 얼리 아답터일 때만 이 아이디어를 받아들임
// 이 때, 트리 내에서 모든 개인이 새로운 아이디어를 수용하기 위하여 필요한 최소 얼리 어답터의 수를 구하는 문제

const int MAX = 1000001;

int N;

std::vector<int> graph[MAX];
bool visited[MAX];

// DP[i][0] : i번째 사람이 얼리 어답터가 아닌 경우
// DP[i][1] : i번째 사람이 얼리 어답터인 경우
int DP[MAX][2];

void DFS(int cur) {
	visited[cur] = true;

	// 현재 사람이 얼리 어답터가 아닌 경우 포함하지 않음(0으로 시작)
	// 현재 사람이 얼리 어답터인 경우 포함함(1로 시작)
	DP[cur][0] = 0;
	DP[cur][1] = 1;

	for (int node : graph[cur]) {
		if (!visited[node]) {
			DFS(node);

			// 현재 사람이 얼리 어답터가 아닌 경우, 하위 노드들은 모두 얼리 어답터여야 함  
			// 현재 사람이 얼리 어답터인 경우, 하위 노드들은 얼리 어답터가 아니여도 상관없기 때문에 가장 작은 값들을 취해서 더함
			DP[cur][0] += DP[node][1];
			DP[cur][1] += std::min(DP[node][0], DP[node][1]);
		}
	}
}

int main() {
	std::cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1);

	// 출력 시 어느 노드여도 상관은 없음
	// 특정 사람이 얼리 어답터인 경우와 그렇지 않은 경우 중 최솟값을 구함 
	std::cout << std::min(DP[1][0], DP[1][1]);

	return 0;
}