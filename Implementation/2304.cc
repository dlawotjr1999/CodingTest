#include <iostream>
#include <vector>
#include <algorithm>

// 폭이 1m인 N 개의 막대 기둥이 일렬로 세워져 있을 때, 이 기둥들을 활용한 창고의 지붕을 다음과 같이 만들고자 함
// 1. 지붕은 수평 부분과 수직 부분으로 구성되며, 모두 연결되어야 함
// 2. 지붕의 수평 부분은 반드시 어떤 기둥의 윗면과 닿아야 함
// 3. 지붕의 수직 부분은 반드시 어떤 기둥의 옆면과 닿아야 함
// 4. 지붕의 가장자리는 땅에 닿아야 함
// 5. 비가 올 때 물이 고이지 않도록 지붕의 어떤 부분도 오목하게 들어간 부분이 없어야 함
// 위 규칙을 모두 만족하면서 지붕을 만들 때 가장 작은 창고 다각형의 면적을 구하는 문제

int answer;

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < N; ++i) {
		int l, h;
		std::cin >> l >> h;
		vec.emplace_back(l, h);
	}

	// 왼쪽 면의 위치를 바탕으로 정렬
	std::sort(vec.begin(), vec.end());

	// 가장 높은 기둥의 높이와 그 위치를 구함
	// 이 기둥을 기준으로 왼쪽은 순방향, 오른쪽은 역방향으로 탐색하며 면적을 구함
	int max_idx = 0, max_h = 0;
	for (int i = 0; i < N; ++i) {
		if (max_h < vec[i].second) {
			max_idx = i;
			max_h = vec[i].second;
		}
	}

	// 가장 높은 기둥 부분의 높이를 먼저 저장하고, 이 기둥 이전까지 탐색
	// 오목한 부분이 발생하면 안 되므로, 다음 기둥의 현재 높이보다 크면 l,h 갱신
	// 이 부분의 연산이 끝나면 가장 왼쪽 기둥부터 가장 높은 기둥까지의 면적이 구해짐
	answer = max_h;
	int l = vec[0].first; int h = vec[0].second;
	for (int i = 1; i < max_idx + 1; ++i) {
		if (h <= vec[i].second) {
			answer += (vec[i].first - l) * h;
			l = vec[i].first;
			h = vec[i].second;
		}
	}

	// 좌표는 기둥의 왼쪽 면의 위치이기 때문에 오른쪽 부분은 여기에 1을 더해서 구함
	// 왼쪽 부분과 마찬가지로 현재 높이보다 높은 기둥을 만나면 l, h 갱신
	l = vec[N - 1].first + 1;
	h = vec[N - 1].second;
	for (int i = N - 1; i > max_idx - 1; --i) {
		if (vec[i].second >= h) {
			answer += (l - vec[i].first - 1) * h;
			l = vec[i].first + 1;
			h = vec[i].second;
		}
	}

	// (가장 높은 기둥의 면적) + (왼쪽 부분의 면적) + (오른쪽 부분의 면적)이 도출됐으므로 총 면적이 구해짐 
	std::cout << answer;
	return 0;
}