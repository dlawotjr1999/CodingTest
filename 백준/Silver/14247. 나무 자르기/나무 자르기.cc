#include <iostream>
#include <vector>
#include <algorithm>

long long answer;

int main() {
	int n;	std::cin >> n;

	std::vector<long long> trees(n);
	std::vector<long long> tree_len(n);

	for (int i = 0; i < n; ++i)
		std::cin >> trees[i];
	for (int i = 0; i < n; ++i)
		std::cin >> tree_len[i];

	std::vector<std::pair<long long, long long>> vec;
	for (int i = 0; i < n; ++i)
		vec.emplace_back(tree_len[i], trees[i]);
	std::sort(vec.begin(), vec.end());

	for (int i = 0; i < n; ++i) {
		answer += vec[i].second + vec[i].first * i;
	}

	std::cout << answer;
	return 0;
}