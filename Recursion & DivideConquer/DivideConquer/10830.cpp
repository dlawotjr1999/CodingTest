#include <iostream>
#include <vector>

typedef long long ll;
typedef std::vector<std::vector<ll>> Matrix;

int N; ll B;

Matrix operator*(const Matrix& lhs, const Matrix& rhs) {
	Matrix result(N, std::vector<ll>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				result[i][j] += lhs[i][k] * rhs[k][j];
				result[i][j] %= static_cast<ll>(1000);
			}
		}
	}
	return result;
}

Matrix divide(const Matrix& matrix, ll pow) {
	if (pow == 1)
		return matrix;
	if (pow % 2 == 0) {
		Matrix temp = divide(matrix, pow / 2);
		return temp * temp;
	}
	else {
		Matrix temp = divide(matrix, pow - 1);
		return matrix * temp;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> B;
	Matrix matrix(N, std::vector<ll>(N));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> matrix[i][j];
		}
	}
	Matrix answer = divide(matrix, B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cout << answer[i][j] % 1000 << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}