#include <iostream>
#include <vector>
#include <algorithm>

// 가능한 암호의 조합들을 구하는 문제
// 암호는 최소 한 개의 모음과 최소 두 개의 자음으로 이루어져 있음
// 또한 암호를 이루는 알파벳은 암호에서 증가하는 순서로 배열되어 있음

int L, C;
std::vector<char> vec;
std::vector<std::string> answers;

void DFS(int idx, int vowel_cnt, int consonant_cnt, std::string cur) {
	// 길이를 충족하며 모음이 한 개 이상, 자음이 두 개 이상인 경우에 조건을 만족
	if (cur.size() == L && vowel_cnt >= 1 && consonant_cnt >= 2) {
		answers.emplace_back(cur);
		return;
	}

	// 자음과 모음인 경우를 구분하며 백트래킹 진행
	for (int i = idx; i < C; i++) {
		if (vec[i] == 'a' || vec[i] == 'e' || vec[i] == 'i' || vec[i] == 'o' || vec[i] == 'u') {
			DFS(i + 1, vowel_cnt + 1, consonant_cnt, cur + vec[i]);
		}
		else {
			DFS(i + 1, vowel_cnt, consonant_cnt + 1, cur + vec[i]);
		}
	}
}

int main() {
	std::cin >> L >> C;
	vec.resize(C);

	for (int i = 0; i < C; i++)
		std::cin >> vec[i];

	// 암호는 알파벳이 증가하는 순서로 배열되어 있으므로 정렬이 선행되어야 함
	std::sort(vec.begin(), vec.end());
	DFS(0, 0, 0, "");

	for (auto& answer : answers)
		std::cout << answer << '\n';

	return 0;
}