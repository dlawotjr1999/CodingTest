#include <iostream>
#include <string>
#include <algorithm>

// 입력된 문자열을 규칙에 맞게 뒤집는 문제
// 규칙 : 단어 별로 뒤집되, 꺾쇠 안의 단어들은 그대로 출력

int main() {
	std::string input;

	// 띄어쓰기도 입력받기 위해 getline 사용
	std::getline(std::cin, input);

	std::string result = "";
	std::string temp = "";
	bool isTag = false;

	for (char c : input) {

		// '<'일 때 이전의 단어들은 모두 뒤집어서 result에 저장하고 isTag를 true로 설정 
		if (c == '<') {
			std::reverse(temp.begin(), temp.end());
			result += temp;
			temp.clear();

			isTag = true;
			result += c;
		}

		// '>'일 때, isTag를 false로 설정하고 '>'를 result에 저장
		else if (c == '>') {
			isTag = false;
			result += c;
		}

		// '<' 이후의 단어는 '>'를 만나기 전까지 그대로 result에 저장
		else if (isTag) {
			result += c;
		}

		// 일반 문자들은 차례대로 temp에 저장함
		// 만약 공백문자를 만나면 temp에 저장된 문자열을 뒤집고 result에 저장
		else {
			if (c == ' ') {
				std::reverse(temp.begin(), temp.end());
				result += temp + ' ';
				temp.clear();
			}
			else {
				temp += c;
			}
		}
	}

	// 마지막 문자열 처리
	std::reverse(temp.begin(), temp.end());
	result += temp;

	std::cout << result;
	return 0;
}
