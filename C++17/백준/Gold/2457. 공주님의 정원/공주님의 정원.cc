#include <iostream>
#include <vector>
#include <algorithm>

int N;
int answer;

int days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
std::vector<std::pair<int, int>> flowers;

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

		for (; i < N; ++i) {
			if (flowers[i].first <= start_day) {
				long_end = std::max(long_end, flowers[i].second);
			}
			else break;
		}
		if (long_end == 0) {
			std::cout << '0';
			return 0;
		}

		start_day = long_end;
		answer++;
	}

	std::cout << answer;
	return 0;
}