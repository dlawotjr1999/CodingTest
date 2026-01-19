#include <iostream>
#include <vector>
#include <algorithm>

// 산 속에 있는 나무들은 매일 밤마다 자라는 길이가 각각 다름
// 따라서 어느 나무를 먼저 잘라가느냐에 따라서 총 구할 수 있는 나무의 양이 다름
// 이 때, 얻을 수 있는 최대 나무 양을 구하는 문제

long long answer;

int main() {
	int n;	std::cin >> n;

	std::vector<long long> trees(n);
	std::vector<long long> tree_len(n);

	for (int i = 0; i < n; ++i)
		std::cin >> trees[i];
	for (int i = 0; i < n; ++i)
		std::cin >> tree_len[i];

	// 하루마다 가장 긴 나무를 자르는 방식은 국소 해를 가질 수 있지만, 전역 해를 보장하지는 않음
	// 즉 성장률이 가장 큰 나무를 마지막에 자르는 방식을 채택해야 함
	std::vector<std::pair<long long, long long>> vec;
	for (int i = 0; i < n; ++i)
		vec.emplace_back(tree_len[i], trees[i]);

	// 나무의 성장률을 기준으로 정렬 수행
	std::sort(vec.begin(), vec.end());

	// 성장률이 작은 나무부터 베어 최대 나무 양 계산
	for (int i = 0; i < n; ++i) {
		answer += vec[i].second + vec[i].first * i;
	}

	std::cout << answer;
	return 0;
}