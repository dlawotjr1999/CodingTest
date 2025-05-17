#include <iostream>
#include <vector>
#include <tuple>
#include <limits>

// Bellman-Ford 알고리즘 구현 문제

typedef std::tuple<int, int, int> edge;

constexpr int MAX = 500;
constexpr long INF = std::numeric_limits<long>::max();

int N, M;
bool IsCycle;

std::vector<edge> graph;
std::vector<long> dist;

void BellmanFord() {
	dist[1] = 0;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < M; j++) {
			edge m_edge = graph[j];

			int start = std::get<0>(m_edge);
			int end = std::get<1>(m_edge);
			int time = std::get<2>(m_edge);

			if (dist[start] != INF && dist[end] > dist[start] + time)
				dist[end] = dist[start] + time;
		}
	}

	for (int i = 0; i < M; i++) {
		edge m_edge = graph[i];

		int start = std::get<0>(m_edge);
		int end = std::get<1>(m_edge);
		int time = std::get<2>(m_edge);

		if (dist[start] != INF && dist[end] > dist[start] + time)
			IsCycle = true;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	dist.resize(N + 1, INF);
	
	for (int i = 0; i < M; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;
		graph.emplace_back(a, b, c);
	}

	BellmanFord();

	if (!IsCycle) {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF)
				std::cout << -1 << '\n';
			else
				std::cout << dist[i] << '\n';
		}
	}
	else
		std::cout << -1 << '\n';
}
