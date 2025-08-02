#include <bits/stdc++.h>

// 특정 단어가 중복을 제외하고 몇 번 등장하는지 횟수를 세는 함수가 있을 때, 그 규칙은 아래와 같음
// 예를 들어, 문서가 abababa이고 찾으려는 단어가 ababa라면, 이 단어를 0번부터 찾을 수 있고 2번부터도 찾을 수 있지만, 동시에 셀 수는 없음
// 이 때, 이 함수를 통해 구해진 단어의 등장 횟수를 구하는 문제

int cnt;

int main() {
	// 공백 문자가 포함된 문자열도 가능하므로 getline으로 입력을 받음
	std::string str;
	std::getline(std::cin, str);

	std::string input;
	std::getline(std::cin, input);

	int i = 0;
	while (i + input.length() <= str.length()) {
		std::string temp(str.begin() + i, str.begin() + i + input.length());
		
		// input과 일치하는 경우 input의 길이만큼 건너뛴 위치에서부터 탐색(중복 제외를 위함)
		if (temp == input) {
			cnt++;
			i += input.length();
		}
		// input과 일치하지 않는 경우 다음 문자 탐색
		else 
			i++;
	}

	std::cout << cnt;
	return 0;
}