#include <bits/stdc++.h>

// 한 젖소가 1번부터 N번까지의 체크포인트를 거치는 마라톤을 하고 있으며, 하나의 체크포인트는 건너뛰고자 함
// 이 때, 체크포인트 한 개를 건너뛰고 달릴 수 있는 최소 거리를 구하는 문제
// 각 지점의 거리는 Manhattan Distance(|x1-x2| + |y1-y2|)로 계산함

int answer = INT_MAX;

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec;
	std::vector<int> dist_vec;

	for (int i = 0; i < N; ++i) {
		int x, y;
		std::cin >> x >> y;
		vec.emplace_back(x, y);
	}

	int dist = 0;

	// 전체 거리를 계산
	for (int i = 0; i < N - 1; ++i)
		dist += (abs(vec[i].first - vec[i + 1].first) + abs(vec[i].second - vec[i + 1].second));

	// 특정 지점을 건너뛸 때의 거리 계산
	// 예를 들어 (i+1)번 지점을 건너뛰어 i번 지점에서 (i+2)번 지점으로 바로 가는 거리는 아래와 같음
	// 전체 거리 - ((i번 지점부터 (i+1)번 지점까지의 거리) + ((i+1)번 지점부터 (i+2)번 지점까지의 거리)) + (i번 지점부터 (i+2)번 지점까지의 거리)
	// 이는 기존의 연속된 지점의 거리를 빼고 건너뛴 지점의 거리로 대체하기 때문임
	for (int i = 1; i < N - 1; ++i) {
		int removed1 = (abs(vec[i - 1].first - vec[i].first) + abs(vec[i - 1].second - vec[i].second));
		int removed2 = (abs(vec[i].first - vec[i + 1].first) + abs(vec[i].second - vec[i + 1].second));
		int direct = (abs(vec[i - 1].first - vec[i + 1].first) + abs(vec[i - 1].second - vec[i + 1].second));
		
		int temp = dist - (removed1 + removed2) + direct;
		dist_vec.push_back(temp);
	}

	// 각 지점들을 건너뛰어 갱신된 거리들 중 가장 짧은 거리를 채택함
	answer = *std::min_element(dist_vec.begin(), dist_vec.end());
	std::cout << answer;
	return 0;
}
