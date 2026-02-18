#include <bits/stdc++.h>

// 어떤 편의점은 아래와 같은 임금 체계를 가지고 있음
// - 각 날마다 일의 차이때문에 일마다 급여가 정해져 있음
// - 오차 없이 일급을 당일에 받음
// - 정해진 일 수 만큼만 일을 시킴
// - 한 번이라도 퇴직한 자를 다시 취직 시키지 않음. 즉, 만약 취직을 한다면 일을 시작 한 날부터 끝날 때까지 하루도 빠지면 안 됨
// n일 후까지의 일급 통계를 알고 있을 때, m일동안 벌 수 있는 최대 이익을 구하는 문제

long long answer;

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> costs(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> costs[i];
	}

	// 처음 m일 동안 벌 수 있는 이익 계산(window 초기화)
	long long cur = 0;
	for (int i = 0; i < m; ++i) 
		cur += costs[i];
	answer = cur;

	// 하루씩 넘어가면서 벌 수 있는 최대 이익 갱신(window 이동)
	for (int i = m; i < n; ++i) {
		cur += (costs[i] - costs[i - m]);
		answer = std::max(cur, answer);
	}

	std::cout << answer;
	return 0;
}