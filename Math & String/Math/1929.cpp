#include <iostream>
#define MAX 1000000

int arr[MAX + 1]{ 0, };

// �����佺�׳׽��� ü�� Ȱ���� �Ҽ� �Ǻ� ����
// �ð� ���⵵ : O(n log(log n))

int main() {

	int start, end;
	std::cin >> start >> end;

	for (int i = 2; i <= end; i++) {
		arr[i] = i;
	}

	// ��� �ռ����� ��N ������ ����� ������ ���� �̿�
	// ��, ��N������ �˻��ϸ� �������� �ڵ����� ó����
	for (int i = 2; i * i <= end; i++) {
		if (arr[i] == 0) continue;
		
		// �� ���� ������� ����
		// i�� ������� 2*i, 3*i, 4*i, ... �̹Ƿ� �����ؾ� ��
		for (int j = i * i; j <= end; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = start; i <= end; i++) {
		if (arr[i] != 0) {
			std::cout << arr[i] << "\n";
		}
	}
}