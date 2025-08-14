#include <bits/stdc++.h>

int main() {
	int N, C;
	std::cin >> N >> C;
	
	std::vector<std::pair<int, int>> vec;
	std::unordered_map<int, int> freq;
	for (int i = 0; i < N; ++i) {
		int elm;
		std::cin >> elm;
		
		if (freq[elm]++ == 0) {
			vec.emplace_back(elm, i);
		}
	}

	std::sort(vec.begin(), vec.end(), [&](const auto& l, const auto& r) {
		if (freq[l.first] != freq[r.first])
			return freq[l.first] > freq[r.first];
		else
			return l.second < r.second;
	});

	for (const auto& elm : vec) {
		for (int i = 0; i < freq[elm.first]; ++i) {
			std::cout << elm.first << ' ';
		}
	}

	return 0;
}