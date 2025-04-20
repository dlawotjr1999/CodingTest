#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

// 주어진 좌표들을 위치로 가진 별들이 있을 때, 이들을 이어 별자리를 만든다
// 별자리를 이루는 두 선은 두 별을 이은 직선이며, 모든 별들은 별자리 내에서 직간접적으로 이어져 있다
// 선을 하나 이을 때마다 그 거리만큼 비용이 발생할 때, 별자리를 만드는 최소비용을 구하는 문제

std::vector<std::pair<float, float>> star;
std::vector<bool> visited;

float Prim(int start) {
	std::priority_queue<std::pair<float, float>, std::vector<std::pair<float, float>>, std::greater<std::pair<float, float>>> pq;
	float total_cost = 0;
	int connected = 0;

	pq.emplace(0, start);

	while (!pq.empty()) {
		float cost = pq.top().first;
		int current = pq.top().second;
		pq.pop();

		if (visited[current])
			continue;
		visited[current] = true;
		total_cost += cost;
		connected++;

		if (connected == star.size())
			break;

		for (int i = 0; i < star.size(); i++) {
			if (!visited[i]) {
				auto distance = [](std::pair<float, float> a, std::pair<float, float> b) {
					return std::sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
				};

				// 두 별 사이의 거리로 비용을 구한 다음, 거리와 별의 index를 최소 힙에 삽입
				float dist = distance(star[current], star[i]);
				pq.emplace(dist, i);
			}
		}
	}

	return total_cost;
}

int main() {
	int n;
	std::cin >> n;

	star.resize(n);
	visited.resize(n, false);

	for (int i = 0; i < n; i++) {
		float x, y; std::cin >> x >> y;
		star[i] = { x, y };
	}
	
	// 소수점 둘째 자리까지 표현
	std::cout << std::fixed;
	std::cout.precision(2);

	// 맨 처음 입력한 별부터 별자리 생성
	std::cout << Prim(0);

	return 0;
}