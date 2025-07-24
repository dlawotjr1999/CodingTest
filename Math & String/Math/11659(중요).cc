#include <iostream>
#include <vector>

// �� N���� �־����� ��, i��° ������ j��° ������ ���� ���ϴ� ����

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	// ���� �� �˰����� �Ʒ��� ����
	// 1. �Է� �迭 A�� �������� ������ ���� n+1�� prefix �迭 P�� �����ϰ� P[0] = 0���� �ʱ�ȭ
	// 2. i = 1���� n���� P[i] = P[i-1] + A[i]�� ����Ͽ� ��ü �迭�� �������� ����
	// 3. [a, b] ������ ���� P[b] - P[a - 1]�� ���� �� ���� 
	std::vector<int> vec(N + 1);
	for (int i = 1; i <= N; ++i) {
		std::cin >> vec[i];
		vec[i] += vec[i - 1];
	}

	for (int i = 0; i < M; ++i) {
		int a, b;
		std::cin >> a >> b;

		std::cout << vec[b] - vec[a - 1] << '\n';
	}

	return 0;
}