#include <bits/stdc++.h>

// 문자열 S가 주어졌을 때, S의 서로 다른 부분 문자열의 개수를 구하는 문제

int main() {
	std::string str; std::cin >> str;

	std::unordered_set<std::string> s;
	
	// 부분 문자열은 길이가 1 이상이어야 하며, 그 자체도 부분 문자열이 될 수 있음
	for (int len = 1; len <= str.length(); ++len) {
		// 현재 위치에서 길이가 len인 부분 문자열 추출
		for (int i = 0; i + len <= str.length(); ++i) {

			// 현재 위치로부터 len만큼의 부분 문자열 추출 후 s에 삽입
			// s는 unordered_set이므로 중복되는 문자열은 무시됨
			std::string tmp = str.substr(i, len);
			s.insert(tmp);
		}
	}

	std::cout << s.size();
	return 0;
}