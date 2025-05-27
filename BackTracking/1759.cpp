#include <iostream>
#include <vector>
#include <algorithm>

int L, C;
std::vector<char> vec;
std::vector<std::string> answers;

void DFS(int idx, int vowel_cnt, int consonant_cnt, std::string cur) {
	if (cur.size() == L && vowel_cnt >= 1 && consonant_cnt >= 2) {
		answers.emplace_back(cur);
		return;
	}

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

	std::sort(vec.begin(), vec.end());
	DFS(0, 0, 0, "");

	for (auto& answer : answers)
		std::cout << answer << '\n';

	return 0;
}