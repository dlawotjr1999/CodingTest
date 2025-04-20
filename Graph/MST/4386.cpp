#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

// �־��� ��ǥ���� ��ġ�� ���� ������ ���� ��, �̵��� �̾� ���ڸ��� �����
// ���ڸ��� �̷�� �� ���� �� ���� ���� �����̸�, ��� ������ ���ڸ� ������ ������������ �̾��� �ִ�
// ���� �ϳ� ���� ������ �� �Ÿ���ŭ ����� �߻��� ��, ���ڸ��� ����� �ּҺ���� ���ϴ� ����

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

				// �� �� ������ �Ÿ��� ����� ���� ����, �Ÿ��� ���� index�� �ּ� ���� ����
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
	
	// �Ҽ��� ��° �ڸ����� ǥ��
	std::cout << std::fixed;
	std::cout.precision(2);

	// �� ó�� �Է��� ������ ���ڸ� ����
	std::cout << Prim(0);

	return 0;
}