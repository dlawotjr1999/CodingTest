#include <iostream>
#include <vector>
#include <algorithm>

// 222-풀링을 진행한 후 최종적으로 남아있는 값을 구하는 문제
// 222-풀링은 아래와 같이 진행함
// 1. 행렬을 2×2 정사각형으로 나눔
// 2. 각 정사각형에서 두 번째로 큰 수만 남김
// 3. 2번 과정에 의해 행렬의 크기가 줄어들게 됨

int matrix[1024][1024];

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> matrix[i][j];
		}
	}

	// 사이즈가 1이 될 때까지 반복
	while (N != 1) {
		// 저장할 값으로 이루어진 matrix는 기존 matrix의 절반 크기를 가지므로 아래와 같이 선언
		std::vector<std::vector<int>> temp(N / 2, std::vector<int>(N / 2));

		// 2 * 2 matrix 내에서 연산을 진행하므로 두 칸씩 건너 뛰어야 함
		for (int i = 0; i < N; i += 2) {
			for (int j = 0; j < N; j += 2) {
				std::vector<int> vec(4);

				vec[0] = matrix[i][j];
				vec[1] = matrix[i + 1][j];
				vec[2] = matrix[i][j + 1];
				vec[3] = matrix[i + 1][j + 1];

				// temp에 두 번째로 큰 수를 저장
				std::sort(vec.begin(), vec.end(), std::greater<int>());
				temp[i / 2][j / 2] = vec[1];
			}
		}
		N /= 2;

		// 기존 matrix에 연산 결과를 저장함
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				matrix[i][j] = temp[i][j];
			}
		}
	}

	std::cout << matrix[0][0];

	return 0;
}