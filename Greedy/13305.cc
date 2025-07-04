#include <iostream>
#include <vector>

// N���� ���ð� ���� ��, �� ���� �������� ������ �������� �̵��ϰ��� ��
// �� ������ �����Ҹ��� L�� ������ �־������, �� ���� ������ �Ÿ� (N-1)�� �־���
// �� �� ���� ���� ���ÿ��� ���� ������ ���÷� �̵��ϴ� �ּ� ����� ���ϴ� ����

std::vector<long long> dists;
std::vector<long long> costs;

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N - 1; ++i) {
		long long dist; std::cin >> dist;
		dists.emplace_back(dist);
	}

	for (int i = 0; i < N; ++i) {
		long long node; std::cin >> node;
		costs.emplace_back(node);
	}

	long long answer = 0;
	long long cur = costs[0];
	
	for (int i = 0; i < N - 1; ++i) {
		// (���� ������ ������ * ���� ���������� �Ÿ�)�� ���� �������� �̵� 
		answer += cur * dists[i];

		// ���� ������ ������ �� ���� ��� �� ������� cur ���� 
		if (costs[i + 1] < cur) {
			cur = costs[i + 1];
		}
	}

	std::cout << answer;
	return 0;
}