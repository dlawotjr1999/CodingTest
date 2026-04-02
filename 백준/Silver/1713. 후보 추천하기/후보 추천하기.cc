#include <bits/stdc++.h>
#include <unordered_map>

int main() {
	int N, T;
	std::cin >> N >> T;

	std::vector<std::pair<int, int>> results; // (사람, 시간)
	std::unordered_map<int, int> info; // (사람, 추천횟수)

	for (int t = 0; t < T; ++t) {
		int elm; std::cin >> elm;

		auto it = std::find_if(results.begin(), results.end(), [&](const auto& p) {
				return p.first == elm;
		});
		if (it != results.end()) {
			info[elm]++;
			continue;
		}

		if (results.size() < N) {
			results.emplace_back(elm, t);
			info[elm]++;
		}
		else {
			int min_idx = 0, min_val = 10000;

			for (int i = 0; i < (int)results.size(); ++i) {
				if (info[results[i].first] < min_val) {
					min_val = info[results[i].first];
					min_idx = i;
				}

				else if (info[results[i].first] == min_val) {
					if (results[i].second < results[min_idx].second) {
						min_idx = i;
					}
				}
			}
			info[results[min_idx].first] = 0;

			results[min_idx] = { elm, t };
			info[results[min_idx].first]++;
		}
	}

	std::sort(results.begin(), results.end());
	for (auto x : results) {
		std::cout << x.first << ' ';
	}
	return 0;
}