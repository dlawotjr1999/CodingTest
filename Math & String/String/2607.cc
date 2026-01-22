#include <bits/stdc++.h>

// 모두 대문자 알파벳으로 이루어진 두 단어가 '같은 종류의 문자로 이루어져 있으며, 같은 문자가 같은 갯수만큼 있으면' 같은 구성을 가짐
// 두 단어가 같은 구성일 때, 또는 한 단어에서 한 문자를 더하거나 빼거나, 하나의 문자를 다른 문자로 바꾸어 나머지 한 단어와 같은 구성을 갖게 되는 경우에는 비슷한 단어임
// 여러 개의 서로 다른 단어가 주어질 때, 첫 번째 단어와 비슷한 단어가 모두 몇 개인지 구하는 문제

int answer;

int main() {
	int N; std::cin >> N;

	std::string base;
	std::cin >> base;

	// 기준 문자열의 각 문자의 등장횟수 저장
	std::vector<int> base_cnt(26, 0);
	for (char c : base) {
		base_cnt[c - 'A']++;
	}

	// 비교 문자열 탐색
	for (int i = 1; i < N; ++i) {
		std::string comp;
		std::cin >> comp;

		int diff = 0;

		// 비교 문자열의 각 문자의 등장횟수 저장
		std::vector<int> comp_cnt(26, 0);
		for (char c : comp) {
			comp_cnt[c - 'A']++;
		}

		// 기준 문자열을 구성하는 문자의 빈도와 비교 문자열을 구성하는 문자의 빈도의 차이를 구함
		for (int i = 0; i < 26; ++i) {
			diff += std::abs(comp_cnt[i] - base_cnt[i]);
		}

		// 한 단어에서 한 문자를 더하거나 빼는 경우
		// 두 문자열의 길이 차이는 1, 즉 빈도의 차이도 1이 됨
		if (base.length() != comp.length() && diff <= 1)
			answer++;

		// 하나의 문자를 다른 문자로 바꾸는 경우
		// 두 문자열의 길이는 같지만 서로 존재하지 않는 문자를 각각 하나씩 보유
		// 즉 두 개의 문자(기존 문자열에 하나, 비교 문자열에 하나)에 대해 diff가 발생하므로 차이는 2가 됨 
		else if (base.length() == comp.length() && diff <= 2)
			answer++;
	}

	std::cout << answer;
	return 0;
}