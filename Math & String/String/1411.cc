#include <bits/stdc++.h>

// 어떤 단어 A를 다음과 같은 과정을 만족해서 B로 바꾸면, A와 B는 비슷한 단어라고 할 수 있음 
// 1. 단어 A에 등장하는 모든 알파벳을 다른 알파벳으로 바꿀 수 있으며, 단어에 등장하는 알파벳의 순서는 바뀌지 않음
// 2. 두 개의 다른 알파벳을 하나의 알파벳으로 바꿀 수 없고, 임의의 알파벳을 자기 자신으로 바꾸는 것은 가능함
// 단어가 여러 개 주어졌을 때, 몇 개의 쌍이 비슷한지 구하는 문제

int answer;

int main() {
	int N; std::cin >> N;

	std::vector<std::string> vec;
	for (int i = 0; i < N; ++i) {
		std::string str; std::cin >> str;
		vec.push_back(str);
	}

	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			std::string cur = vec[i];
			std::string tmp = vec[j];

			// 두 개의 다른 알파벳을 하나로 바꿀 수 없기 때문에 각 알파벳의 치환은 일대일대응(전단사)이어야 함
			// 즉 임의의 c->c'에 대해 c'->c도 고유해야 함
			bool isOk = true;

			// m1 : c->c', m2 : c2 : c'->c
			std::unordered_map<char, char> m1, m2;

			// 현재 문자에 대해 key-value 쌍이 존재할 때 매핑 값이 서로 일치하지 않으면 치환 불가능한 단어 쌍
			// 반대로 key-value 쌍이 존재하지 않으면 각 m1, m2에 대해 각 문자들을 key-value로 하여 매핑 진행
			for (int idx = 0; idx < cur.length(); ++idx) {
				if (m1.count(cur[idx]) && m1[cur[idx]] != tmp[idx]) {
					isOk = false;
					break;
				}

				else if (m2.count(tmp[idx]) && m2[tmp[idx]] != cur[idx]) {
					isOk = false;
					break;
				}

				m1[cur[idx]] = tmp[idx];
				m2[tmp[idx]] = cur[idx];
			}

			if(isOk)
				answer++;
		}
	}

	std::cout << answer;
	return 0;
}