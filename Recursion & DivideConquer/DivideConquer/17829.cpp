#include <iostream>
#include <vector>
#include <algorithm>

int matrix[1024][1024];

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> matrix[i][j];
		}
	}

	while (N != 1) {
		std::vector<std::vector<int>> temp(N / 2, std::vector<int>(N / 2));

		for (int i = 0; i < N; i += 2) {
			for (int j = 0; j < N; j += 2) {
				std::vector<int> vec(4);

				vec[0] = matrix[i][j];
				vec[1] = matrix[i + 1][j];
				vec[2] = matrix[i][j + 1];
				vec[3] = matrix[i + 1][j + 1];

				std::sort(vec.begin(), vec.end(), std::greater<int>());

				temp[i / 2][j / 2] = vec[1];
			}
		}
		N /= 2;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				matrix[i][j] = temp[i][j];
			}
		}
	}

	std::cout << matrix[0][0];

	return 0;
}