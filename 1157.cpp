#include <iostream>
#include <string>
#include <algorithm>

// 문제
// 알파벳 대소문자로 된 단어가 주어지면, 이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 단, 대문자와 소문자를 구분하지 않는다.

// 출력
// 첫째 줄에 이 단어에서 가장 많이 사용된 알파벳을 대문자로 출력한다.단, 가장 많이 사용된 알파벳이 여러 개 존재하는 경우에는 ? 를 출력한다.

int main() {
	int cnt[26] = {0,};
	int count;
	std::string s;
	std::string::iterator itr;

	std::cin >> s;
	for (itr = s.begin(); itr != s.end(); itr++) {
		if (*itr >= 97) *itr -= 32; //if (*itr >= 'a') *itr -= 32;
		int j = *itr - 65;
		(cnt[j])++;
	}
	//Uppercase

	int target = *std::max_element(cnt, cnt + 26);
	// 사용된 알파벳의 갯수가 저장된 cnt 배열에서 max 값을 찾아낸다.

	for (int i = 0; i < sizeof(cnt) / sizeof(int); i++) {
		count = std::count(std::begin(cnt), std::end(cnt), target);
	}
	// cnt 배열에서 target만큼의(가장 큰 값) 값을 찾아낸다.

	auto max_index = std::find(std::begin(cnt), std::end(cnt), target);

	if (count > 1) {
		std::cout << '?';
	}
	// 중복된 알파벳이 있을 시 ? 출력

	else {
		int index = std::distance(cnt, max_index);
		index += 65;
		std::cout << (char)index;
	}
	// 그렇지 않을 시 가장 많이 사용된 알파벳 출력

	return 0;
}