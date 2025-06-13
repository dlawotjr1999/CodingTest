#include <iostream>
#include <vector>
#include <algorithm>

// 한 개의 회의실에서 진행할 수 있는 회의들의 최대 갯수를 구하는 문제 
// 각 회의는 겹칠 수 없음

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < N; i++) {
		int start, end;
		std::cin >> start >> end;
		vec.emplace_back(start, end);
	}

	// 각 회의의 시작 시간과 끝나는 시간을 모두 고려하여 정렬 수행
	// 종료 시간이 같은 경우 시작 시간이 더 빠른 회의를 선행하여 정렬
	std::sort(vec.begin(), vec.end(), [&](const auto& a, const auto& b) {
		if (a.second == b.second) 
			return a.first < b.first;
		return a.second < b.second;
	});

	int result = 1;
	int end_time = vec[0].second;

	// 첫 회의가 끝나고 다음 회의의 시작 시간이 첫 회의의 종료 시간보다 클 경우에만 회의 수행 가능
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].first >= end_time) {
			result++;
			end_time = vec[i].second;
		}
	}

	std::cout << result;
	return 0;
}
