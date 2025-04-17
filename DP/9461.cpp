#include <iostream>

// N이 주어졌을 때 파도반 수열 P(N)을 구하는 문제
// 참고 : https://www.acmicpc.net/problem/9461

long long arr[100];

int main() {
	int T;
	std::cin >> T;

	arr[0] = arr[1] = arr[2] = 1;
	arr[3] = arr[4] = 2;

	// 도형의 규칙을 확인하였을 때, i번째 삼각형의 길이는 (i-5)번째 삼각형과 (i-1)번째 삼각형의 길이의 합과 같다 
	// 즉 점화식은 N[i] = N[i - 5] + N[i - 1]
	for (int i = 5; i < 100; i++) {
		arr[i] = arr[i - 5] + arr[i - 1];
	}

	// 다른 풀이) 단순히 수열의 규칙으로 해결
	//arr[0] = arr[1] = arr[2] = 1;

	//for (int i = 3; i < 100; i++) {
	//	arr[i] = arr[i - 3] + arr[i - 2];
	//}

	while (T--) {
		int N;
		std::cin >> N;
		std::cout << arr[N - 1] << '\n';
	}

	return 0;
}