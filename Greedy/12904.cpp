#include <iostream>
#include <algorithm>

// 주어진 두 조건을 활용하여 S를 T로 바꿀 수 있는지를 구하는 문제
// 조건은 아래와 같다.
// 1. 문자열의 뒤에 A를 추가
// 2. 문자열을 뒤집고 뒤에 B를 추가
// idea : S에서 T로 가는 경우의 수는 매우 많으므로, 반대로 T에서 S를 만들 수 있는지를 확인

std::string S;
std::string T;

int main() {
	std::cin >> S;
	std::cin >> T;

	while (T.length() != S.length()) {

		// 1의 반대 로직 : T의 맨 뒤가 A인 경우 T에서 A를 뺀다
		if (T.back() == 'A')
			T.pop_back();

		// 2의 반대 로직 : T의 맨 뒤가 B인 경우 B를 빼고 T를 뒤집는다
		else {
			T.pop_back();
			std::reverse(T.begin(), T.end());
		}
	}

	std::cout << ((S == T) ? 1 : 0);

	return 0;
}