#include <iostream>

// 오르막수 : 각 자릿수의 숫자들이 모두 오름차순을 이루는 수. 인접한 숫자가 같아도 오름차순으로 취급함
// 이 때, 수의 길이 N이 주어졌을 때, 그 길이만큼의 오르막수들의 갯수를 구하는 문제
// 출력은 N자리 오르막수들의 갯수를 10007로 나눈 나머지 

// 수의 길이를 column으로, 맨 뒷자릿수를 row로 하는 DP 배열 선언
long long DP[1001][10];

int main() {
	int N;
	std::cin >> N;

	// 0부터 9까지는 모두 하나의 오르막 수
	for (int i = 0; i < 10; ++i) {
		DP[1][i] = 1;
	}

	// 표를 채워넣으면 아래와 같은 점화식을 유도할 수 있음
	// DP[i][j] = DP[i - 1][0] + DP[i - 1][1] + ... + DP[i -1][j]
	for (int i = 2; i <= 1000; ++i) {
		long long temp = 0;
		
		for (int j = 0; j < 10; ++j) {
			temp = (temp + DP[i - 1][j]) % 10007;
			DP[i][j] = temp;
		}
	}

	long long answer = 0;
	for (int i = 0; i < 10; ++i) {
		long long num = DP[N][i] % 10007;
		answer += num;
	}

	std::cout << answer % 10007;
}