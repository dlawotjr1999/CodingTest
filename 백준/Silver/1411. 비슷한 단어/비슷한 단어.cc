#include <bits/stdc++.h>

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

			bool isOk = true;
			std::unordered_map<char, char> m1, m2;

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