#include <iostream>
#include <string>
#include <algorithm>

// ����
// ���ĺ� �ҹ��ڷθ� �̷���� �ܾ �־�����.�̶�, �� �ܾ �Ӹ�������� �ƴ��� Ȯ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
// �Ӹ�����̶� ������ ���� ���� �Ųٷ� ���� �� �Ȱ��� �ܾ ���Ѵ�.
// level, noon�� �Ӹ�����̰�, baekjoon, online, judge�� �Ӹ������ �ƴϴ�.

// ���
// ù° �ٿ� �Ӹ�����̸� 1, �ƴϸ� 0�� ����Ѵ�.

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