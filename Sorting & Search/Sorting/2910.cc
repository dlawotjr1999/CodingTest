#include <bits/stdc++.h>

// 수열의 두 수 X와 Y가 있을 때, X가 Y보다 수열에서 많이 등장하는 경우에는 X가 Y보다 앞에 있어야 함
// 만약, 등장하는 횟수가 같다면, 먼저 나온 것이 앞에 있어야 함
// 위의 두 규칙을 만족하는 빈도 정렬을 진행 후, 그 결과를 출력하는 문제 

int main() {
	int N, C;
	std::cin >> N >> C;
	
	std::vector<std::pair<int, int>> vec;
	std::unordered_map<int, int> freq;
	for (int i = 0; i < N; ++i) {
		int elm;
		std::cin >> elm;
		
		// map에는 빈도수를 저장함
		// 만약 빈도수가 0이라면, 원소와 인덱스를 벡터에 저장함
		// 결과적으로 벡터에는 각 원소와 그 원소가 처음 등장한 인덱스가 저장됨
		if (freq[elm]++ == 0) {
			vec.emplace_back(elm, i);
		}
	}

	std::sort(vec.begin(), vec.end(), [&](const auto& l, const auto& r) {
		// 빈도수가 높은 순서대로 정렬하고, 빈도수가 같다면 인덱스가 낮은 순서(먼저 입력된 순서)대로 정렬함
		if (freq[l.first] != freq[r.first])
			return freq[l.first] > freq[r.first];
		else
			return l.second < r.second;
	});

	// freq 참조하여, 벡터에서 각 원소들을 그 빈도만큼 출력함
	for (const auto& elm : vec) {
		for (int i = 0; i < freq[elm.first]; ++i) {
			std::cout << elm.first << ' ';
		}
	}

	return 0;
}