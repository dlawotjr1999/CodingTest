#include <bits/stdc++.h>

// 파일의 이름들이 주어질 때, 파일 별 총 확장자의 종류와 그 갯수를 구하는 문제

int main() {
	int N; std::cin >> N;
	std::map<std::string, int> m;

	for (int i = 0; i < N; ++i) {
		std::string input;
		std::cin >> input;

		// 파일 이름의 맨 뒤부터 '.' 다음 문자까지 추출
		// 추출된 문자열은 반대로 되어 있으므로 다시 뒤집어야 함
		// 이후 map에 저장 후 등장 횟수를 증가
		std::string extension = "";
		for (size_t j = input.length() - 1; j >= 0 && input[j] != '.'; --j) {
			extension += input[j];
		}

		std::reverse(extension.begin(), extension.end());
		m[extension]++;
	}

	// 누적된 파일들의 확장자와 그 갯수 출력
	for (auto& [str, cnt] : m) 
		std::cout << str << ' ' << cnt << '\n';
	
	return 0;
}