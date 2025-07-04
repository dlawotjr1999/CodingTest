#include <iostream>
#include <vector>
#include <algorithm>

// N���� ���� ���ڰ� �����ϸ�, �� ���� ���ڸ� M���� �ο��鿡�� �й��Ϸ��� ��
// ���� ������ ������ �� �� ������ ���� ���̸� ������ �ϰ�, �ϳ��� ���ڴ� ���� �������� ���� �� ����
// �� ��, ���� ������ ���� �� �ִ� �ִ� ���̸� ���ϴ� ����

int main() {
	int M, N;
	std::cin >> M >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// Ž�� ������ ���ڸ� ���� ���� ũ��� �������� ���(1)�� ���� �� ������ ���̷� ������
	int left = 1, right = *std::max_element(vec.begin(), vec.end());
	int answer = 0;
	
	while (left <= right) {
		int mid = (left + right) / 2; 
		int count = 0;

		// ��ü ���ڵ鿡 ���ؼ� Ž��
		// ���õ� ����(mid)���� ���� ������ ���ڵ��� ������ �� ����
		// ������ mid���� �� ���ڴ� ������ �� �ְ�, �� ������ ��(������ �� �ִ� �ο� ��)�� ����
		for (int i = 0; i < N; i++) {
			count += vec[i] / mid; 
		}
		// �ο���(M)���� count�� Ŭ ���, ���ڸ� �� ��� �ڸ� �� �ִٴ� �ǹ��̹Ƿ� left ���� 
		if (count >= M) {
			left = mid + 1;
			answer = mid;
		}
		// �ο������� count�� ���� ���, ���ڸ� �� ª�� �߶�� �Ѵٴ� �ǹ��̹Ƿ� right ����
		else if (count < M) { 
			right = mid - 1;
		}
	}
	std::cout << answer << "\n";

	return 0;
}