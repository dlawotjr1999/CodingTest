#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// S_i에 시작해서 T_i에 끝나는 N개의 수업이 있을 때, 모든 수업이 진행 가능한 최소의 강의실 수를 구하는 문제
// 수업이 끝난 직후에 그 다음 수업을 시작할 수 있음

int cnt;

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<long long, long long>> vec;
	std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq;

	for (int i = 0; i < N; i++) {
		long long s; long long t;
		std::cin >> s >> t;
		vec.emplace_back(s, t);
	}

	// 가장 빨리 수업을 시작하는 수업을 찾기 위해 정렬 진행
	std::sort(vec.begin(), vec.end());

	// 가장 빨리 시작하는 수업의 종료 시간을 최소 힙에 삽입
	pq.push(vec[0].second);

	// 힙의 top에 있는 값(현재 수업의 종료 시간)이 다음 수업 시간의 시작 시간보다 작은 경우를 고려함
	// 이 경우, 한 강의실에서 수업이 가능하므로 현재 수업을 빼고, 다음 수업을 삽입함
	// 그렇지 않은 경우(수업 시간이 겹치는 경우)에는 pop 연산 없이 바로 힙에 삽입
	for (int i = 1; i < N; i++) {
		if (pq.top() <= vec[i].first)
			pq.pop();
		pq.push(vec[i].second);
	}

	// 즉 현재 힙의 크기가 필요한 강의실의 최소 수
	std::cout << pq.size();

	return 0;
}