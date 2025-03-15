#include <iostream>
#include <algorithm>

// 이분탐색 문제
// lower_bound와 upper_bound의 사용법에 대해 숙지

/* NOTE:
	lower_bound : 특정 값 '이상'이 등장하는 iterator를 리턴
	upper_bound : 특정 값 '초과'가 등장하는 iterator를 리턴
	lower_bound를 이용하면 특정 값보다 작은 원소의 갯수를, upper_bound를 이용하면 특정 값보다 큰 원소의 갯수를 알 수 있음
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
