#include <iostream>
#include <vector>

// 여러 개의 상자들이 일렬로 있을 때, 앞에 있는 상자의 크기가 뒤에 있는 상자의 크기보다 작으면 앞에 있는 상자를 뒤에 있는 상자 안에 넣을 수 있음
// 이 때, 한 번에 넣을 수 있는 최대의 상자 갯수를 구하는 문제

int DP[1001];
int answer;

int main() {
	int n;	
	std::cin >> n;

	// 각각의 상자는 최초에 빈 상자 한 개로 존재함
	std::vector<int> vec(n + 1);
	for (int i = 1; i <= n; ++i) {
		std::cin >> vec[i];
		DP[i] = 1;
	}

	// 현재 상자와 그 이전의 상자들의 크기를 비교해 나감
	// 어떤 상자가 그 이전의 상자의 크기보다 크다면 하나를 담을 수 있음(DP[j] + 1)
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j < i; ++j) {
			if (vec[j] < vec[i]) {
				DP[i] = std::max(DP[i], DP[j] + 1);
			}
		}

		// 작은 상자들이 가장 많이 담긴 상자를 갱신해나감
		answer = std::max(answer, DP[i]);
	}

	std::cout << answer;
	return 0;
}