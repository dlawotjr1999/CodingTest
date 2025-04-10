#include <iostream> 
#include <vector>

// 2×n 크기의 직사각형을 1×2, 2×1 타일로 채우는 방법의 수를 구하는 문제

int main() {
	int N;
	std::cin >> N;

	std::vector<long long> DP(N + 1);
	DP[0] = 0; DP[1] = 1; DP[2] = 2;

	/*
		경우의 수는 아래와 같이 두 가지가 있다
		
		1. N-2자리까지 채웠을 때 타일 두 개를 가로로 채우는 방식
		2. N-1자리까지 채웠을 때 타일 하나를 세로로 채우는 방식
		
		즉 N번째에서 타일을 채우는 경우의 수는 N-2번째에서 두 개의 타일을 가로로 채우는 경우의 수와 N-1번째에서 하나의 타일을 세로로 채우는 경우의 수의 합과 같다
		그러므로 점화식은 N[i] = N[i - 1] + N[i - 2]
	*/

	for (int i = 3; i <= N; i++) {
		DP[i] = (DP[i - 2] + DP[i - 1]) % 10007;
	}
	std::cout << DP[N];

	return 0;
}