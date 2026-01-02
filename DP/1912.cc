#include <iostream>
#include <vector>

// n개의 정수로 이루어진 임의의 수열이 주어질 때, 이 중 연속된 몇 개의 수를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하는 문제

int DP[100001];
int answer;

int main() {
	int n;
	std::cin >> n;

	std::vector<int> vec(n + 1);
	for (int i = 1; i <= n; ++i) 
		std::cin >> vec[i];

	// 최초에 정답을 수열의 초항 하나의 값으로 초기화
	answer = vec[1];

	// 현재 원소와 그 이전까지의 합을 더했을 때 값이 작아진다면, 현재 원소만을 취해야 함
	// 즉 현재 원소를 초항으로 하는 연속된 수열을 만들어나감
	// 연속된 구간에서의 합이 가장 큰 수열의 구간합을 갱신함
	for (int i = 2; i <= n; ++i) {
		DP[i] = std::max(DP[i - 1] + vec[i], vec[i]);
		answer = std::max(answer, DP[i]);
	}

	std::cout << answer;
	return 0;
}