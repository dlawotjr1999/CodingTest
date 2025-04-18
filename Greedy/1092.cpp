#include <iostream>
#include <vector>
#include <algorithm>

// �ױ����� ũ������ N�� �ְ�, 1�п� �ڽ��� �ϳ��� �迡 ���� �� �ִ�. ���� ��� ũ������ ���ÿ� �����δ�.
// �� ũ������ ���� ������ ������ �� ���� ���Ѻ��� ���ſ� �ڽ��� ũ�������� ������ �� ����. 
// �� �� ��� �ڽ��� ��� �ű�µ� ��� �ð��� �ּڰ��� ���ϴ� ����

int minute;

int main() {
	int N, M;
	std::cin >> N;
	std::vector<int> crains(N);

	for (int i = 0; i < N; i++) {
		std::cin >> crains[i];
	}

	std::cin >> M;
	std::vector<int> items(M);

	for (int i = 0; i < M; i++) {
		std::cin >> items[i];
	}

	std::sort(crains.rbegin(), crains.rend());
	std::sort(items.rbegin(), items.rend());

	// ������������ ������ �Ǿ��� ��, ���� ���� ũ������ ���� ���ſ� �ڽ��� ���� ���Ѵٸ� �ٸ� ũ���ε� ���� �� �ڽ��� �ű� �� ����
	// �� ��� ũ���ε鿡 ���ؼ� ��� �ڽ����� �ű� �� ����
	if (crains[0] < items[0]) {
		std::cout << -1;
		return 0;
	}

	// moved: �Ű��� �ڽ��� ����
	// idx: ���� ó�� ���� �ڽ��� ����Ű�� �ε���
	int moved = 0;

	// �ڽ��� ��� �ű� ������ �ݺ�
	while (moved < M) {
		int idx = 0;

		// �� ũ���ο� ���� �ݼ�
		for (int i = 0; i < N; i++) {
			// ���� ũ������ �ű� �� �ִ� �ڽ��� ã�� ������ �ݺ�
			while (idx < M) {
				// ũ������ �ڽ��� �ű� �� �ִ� ���
				if (items[idx] != -1 && crains[i] >= items[idx]) {
					// �ڽ��� �ű�� -1�� ����
					items[idx] = -1;
					// �ű� �ڽ� �� ����, ���� �ڽ��� Ȯ��
					moved++; idx++;
					break;
				}
				// ũ������ �ڽ��� �ű��� ���ϴ� ���, ���� �ڽ��� Ȯ�� (�ڽ��� ���԰� ���� ������ �Ű����Ƿ� idx++�� ����)
				idx++;
			}
		}
		minute++;
	}
	std::cout << minute;

	return 0;
}