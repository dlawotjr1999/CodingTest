#include <iostream>
#include <vector>
#include <algorithm>

// N개의 꽃들이 다음 두 조건에 맞춰 피어있어야 함
// 1. 3월 1일부터 11월 30일까지 매일 꽃이 한 가지 이상 피어있어야 함
// 2. 정원에 심는 꽃의 수를 가능한 적게 해야 함
// 이 때 3월 1일부터 11월 30일까지 매일 한 가지 꽃이 피어 있도록 꽃을 선택할 때, 선택한 꽃들의 최소 갯수를 구하는 문제

int N;
int answer;

int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
std::vector<std::pair<int, int>> flowers;

// 월,일로 표현된 날짜를 일수로 치환하는 함수
int month_to_day(int month, int day) {
	int cur_day = 0;

	for (int i = 0; i < month - 1; ++i)
		cur_day += days[i];
	cur_day += day;

	return cur_day;
}

int main() {
	std::cin >> N;

	for(int i = 0; i < N; ++i) {
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;

		int start = month_to_day(a, b);
		int end = month_to_day(c, d);

		flowers.emplace_back(start, end);
	}

	// 날짜 순으로 체크하기 위해 정렬 수행
	std::sort(flowers.begin(), flowers.end());

	int start_day = 60;	// 3월 1일
	int end_day = 334;	// 11월 30일

	if (flowers[0].first > start_day) {
		std::cout << '0';
		return 0;
	}

	int i = 0;
	while (start_day <= end_day) {
		int long_end = 0;

		// 각 꽃들의 피는 날짜, 지는 날짜를 탐색
		// 3월 1일에 꽃이 피어 있는 꽃들을 탐색. 즉 3월 1일 이전에 피는 꽃을 탐색
		// 조건 날짜에 피는 꽃 중, 가장 오랫동안 피어있을 수 있는 꽃을 선택
		for (; i < N; ++i) {
			if (flowers[i].first <= start_day) {
				long_end = std::max(long_end, flowers[i].second);
			}
			else break;
		}

		// long_end가 0이라는 것은 꽃이 피지 않는 날이 존재한다는 의미
		if (long_end == 0) {
			std::cout << '0';
			return 0;
		}

		// 가장 오래 피는 꽃의 지는 날을 갱신하여, 다음 날짜들을 탐색 
		start_day = long_end;
		answer++;
	}

	std::cout << answer;
	return 0;
}