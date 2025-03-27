#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// 1. 자주 나오는 단어일수록 앞에 배치한다.
// 2. 해당 단어의 길이가 길수록 앞에 배치한다.
// 3. 알파벳 사전 순으로 앞에 있는 단어일수록 앞에 배치한다
// 위 세 종류의 배치 순서에 맞게 입력값들을 정렬하는 문제

int main() {
	int N, M;
	std::unordered_map<std::string, int> map;
	
	std::cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		std::string word;
		std::cin >> word;
		map[word]++;
	}

	std::vector<std::pair<std::string, int>> vec(map.begin(), map.end());
	std::sort(vec.begin(), vec.end(), [&](const auto& left, const auto& right) {
		// 1번 조건
		if (left.second != right.second)
			return left.second > right.second;
		// 2번 조건
		if (left.first.size() != right.first.size())
			return left.first.size() > right.first.size();
		// 3번 조건
		return left.first < right.first;
	});

	// M 이상의 길이를 가진 문자열만 출력
	for (const auto& entry : vec) {
		if (entry.first.size() >= M) {
			std::cout << entry.first << '\n';
		}
	}
	
	return 0;
}