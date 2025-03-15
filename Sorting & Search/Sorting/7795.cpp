#include <iostream>
#include <algorithm>

// �̺�Ž�� ����
// lower_bound�� upper_bound�� ������ ���� ����

/* NOTE:
	lower_bound : Ư�� �� '�̻�'�� �����ϴ� iterator�� ����
	upper_bound : Ư�� �� '�ʰ�'�� �����ϴ� iterator�� ����
	lower_bound�� �̿��ϸ� Ư�� ������ ���� ������ ������, upper_bound�� �̿��ϸ� Ư�� ������ ū ������ ������ �� �� ����
*/

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int N, M;
		std::cin >> N >> M;

		int* A = new int[N];
		int* B = new int[M];

		for (int j = 0; j < N; j++)
			std::cin >> A[j];
		for (int j = 0; j < M; j++)
			std::cin >> B[j];

		std::sort(B, B + M);

		int count = 0;
		for (int j = 0; j < N; j++) {
			count += std::lower_bound(B, B + M, A[j]) - B;
		}

		std::cout << count << '\n';

		delete[] A;
		delete[] B;
	}

	return 0;
}
