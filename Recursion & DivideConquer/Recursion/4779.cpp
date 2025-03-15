#include <iostream>
#include <cmath>

// 일반적인 재귀 문제
// 참고 : https://beginnerdeveloper-lit.tistory.com/141

void Cantor(int n) {
	// 종료 조건; N = 0 인 경우 "-" 출력
	if (n == 0) {
		std::cout << '-';
		return;
	}

	// N번째 칸토어 집합은 (N - 1)번째 칸토어 집합을 2개 이은 것
	// 사이에 공백이 (N - 1)번째 칸토어 집합의 크기만큼 있어야 함
	Cantor(n - 1);
	for (int i = 0; i < std::pow(3, (n - 1)); i++) {
		std::cout << " ";
	}
	Cantor(n - 1);
}

int main() {
	int N;

	while (std::cin >> N) {
		Cantor(N);
		std::cout << "\n";
	}

	return 0;
}