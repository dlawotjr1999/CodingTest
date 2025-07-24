#include <iostream>
#include <vector>

// 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 문제

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N, M;
	std::cin >> N >> M;

	// 구간 합 알고리즘은 아래와 같음
	// 1. 입력 배열 A의 누적합을 저장할 길이 n+1의 prefix 배열 P를 선언하고 P[0] = 0으로 초기화
	// 2. i = 1부터 n까지 P[i] = P[i-1] + A[i]를 계산하여 전체 배열의 누적합을 구함
	// 3. [a, b] 구간의 합은 P[b] - P[a - 1]로 구할 수 있음 
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