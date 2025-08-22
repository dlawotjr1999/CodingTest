#include <bits/stdc++.h>

// N개의 도시가 있을 때, 여행 일정에 따라 가고자 하는 도시들을 모두 순회할 수 있는지 판별하는 문제
// 도시는 양방향으로 연결되어 있지만, 도시 간 모든 도로는 연결되어 있지 않음
// 또한 같은 도시를 여러 번 거치면서 여행을 하는 것이 가능함

// 모든 경로를 방문할 수 있는 경우는 여행 계획 내 각 도시들이 하나로 연결되어 있는 경우임(즉, 하나의 컴포넌트로 구성됨)
// DFS/BFS를 통해 컴포넌트의 수를 구할 수도 있지만, Union-Find를 활용하여 각 도시들이 연결되어 있는지(root가 동일한지)를 판별함

int cities[201][201];
std::vector<int> union_vec;
std::vector<int> plans;

int Find(int parent) {
	if (parent == union_vec[parent])
		return parent;
	return union_vec[parent] = Find(union_vec[parent]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);

	if (a == b) return;
	union_vec[b] = a;
}

int main() {
	int N, M;
	std::cin >> N;
	std::cin >> M;
	union_vec.resize(N + 1, 0);

	for(int i = 1; i <= N; ++i) {
		union_vec[i] = i;

		for(int j = 1; j <= N; ++j) {
			std::cin >> cities[i][j];
		}	
	}

	for(int i = 0; i < M; ++i) {
		int plan;
		std::cin >> plan;
		plans.push_back(plan);
	}

	// i와 j가 같은 집합인지 확인하고, 다른 경우에는 Union 시행
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if(cities[i][j] && Find(i) != Find(j))
				Union(i, j);
		}
	}

	// 입력된 여행 계획 중 첫 번째 도시부터 방문
	int root = union_vec[plans[0]];	
	for (int i = 1; i < M; ++i) {
		if (Find(plans[i]) != root) {
			std::cout << "NO";
			return 0;
		}
	}

	std::cout << "YES";
	return 0;
}