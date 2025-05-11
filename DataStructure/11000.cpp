#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// S_i�� �����ؼ� T_i�� ������ N���� ������ ���� ��, ��� ������ ���� ������ �ּ��� ���ǽ� ���� ���ϴ� ����
// ������ ���� ���Ŀ� �� ���� ������ ������ �� ����

int cnt;

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<long long, long long>> vec;
	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

	for (int i = 0; i < N; i++) {
		long long s; long long t;
		std::cin >> s >> t;
		vec.emplace_back(s, t);
	}

	// ���� ���� ������ �����ϴ� ������ ã�� ���� ���� ����
	std::sort(vec.begin(), vec.end());

	// ���� ���� �����ϴ� ������ ���� �ð��� �ּ� ���� ����
	pq.push(vec[0].second);

	// ���� top�� �ִ� ��(���� ������ ���� �ð�)�� ���� ���� �ð��� ���� �ð����� ���� ��츦 �����
	// �� ���, �� ���ǽǿ��� ������ �����ϹǷ� ���� ������ ����, ���� ������ ������
	// �׷��� ���� ���(���� �ð��� ��ġ�� ���)���� pop ���� ���� �ٷ� ���� ����
	for (int i = 1; i < N; i++) {
		if (pq.top() <= vec[i].first)
			pq.pop();
		pq.push(vec[i].second);
	}

	// �� ���� ���� ũ�Ⱑ �ʿ��� ���ǽ��� �ּ� ��
	std::cout << pq.size();

	return 0;
}