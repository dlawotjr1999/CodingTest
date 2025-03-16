#include <iostream>
#include <string>
#include <algorithm>

// 문제
// 알파벳 소문자로만 이루어진 단어가 주어진다.이때, 이 단어가 팰린드롬인지 아닌지 확인하는 프로그램을 작성하시오.
// 팰린드롬이란 앞으로 읽을 때와 거꾸로 읽을 때 똑같은 단어를 말한다.
// level, noon은 팰린드롬이고, baekjoon, online, judge는 팰린드롬이 아니다.

// 출력
// 첫째 줄에 팰린드롬이면 1, 아니면 0을 출력한다.

bool is_palindrome(const std::string& s) {
	std::string rev;
	std::string::const_reverse_iterator itr = s.crbegin();

	while (itr != s.crend()) {
		rev = rev.append(1, *(itr++));
	};

	if (s == rev) 
		return 1;
	else 
		return 0;
}

int main() {
	std::string s;
	std::cin >> s;
	std::cout << is_palindrome(s) << std::endl;
}