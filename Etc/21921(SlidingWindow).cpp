#include <iostream>
#include <vector>
#include <map>

// 주어진 기간동안 가장 많이 들어온 방문자 수와 기간이 몇 개 있는지 구하는 문제

std::vector<int> people;
std::map<int, int> map;

int main() {
	int N, X;
	std::cin >> N >> X;

	people.resize(N);

	for (int& person : people) {
		std::cin >> person;
	}

	// 최초 window 계산
	int cur_sum = 0;
	for (int i = 0; i < X; i++) {
		cur_sum += people[i];
	}
	
	int max_sum = cur_sum;
	int cnt = 1;

	// 다음 window의 누적 방문자 수 계산
	// 이전 window의 초항은 빼고, 다음날의 방문자 수를 더함으로써 다음 window를 계산할 수 있음
	for (int i = X; i < N; i++) {
		cur_sum += (people[i] - people[i - X]);

		// 이전 누적 방문자 수보다 현재 누적 방문자 수가 많으면 갱신
		if (cur_sum > max_sum) {
			max_sum = cur_sum;
			cnt = 1;
		}
		else if (cur_sum == max_sum)
			cnt++;
	}

	if (max_sum == 0) 
		std::cout << "SAD";
	else
		std::cout << max_sum << '\n' << cnt;

	return 0;
}