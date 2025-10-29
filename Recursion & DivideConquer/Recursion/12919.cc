#include <iostream>
#include <algorithm>

// 두 문자열 S와 T가 있을 때 아래 연산들을 통해 S를 T로 바꾸고자 함
// 1. 문자열 뒤에 A를 추가함
// 2. 문자열 뒤에 B를 추가하고 문자열을 뒤집음(reverse)
// 이 때, S를 T로 바꿀 수 있는지를 확인하는 문제

// S에서 T로 바꾸는 경우의 수가 여러 가지가 있을 수 있음
// 반대로 T를 S로 바꿀 수 있는지 확인하는 방법을 사용함

std::string S, T;
bool isPossible;

// t가 1번, 2번 모두의 경우에 해당할 수 있으므로 if-else if가 아닌 if-if로 계산해야함
void Solve(std::string& t) {
	// 연산 결과로 만들어진 t가 S와 같다면 S는 T로 연산이 가능함
	if (t == S) {
		isPossible = true;
		return;
	}

	// t의 길이가 S의 길이보다 짧아지면 종료
	if (t.length() < S.length())
		return;
	
	// t의 맨 앞 문자가 B인 경우, BS'이므로 2번 연산을 반대로 수행함
	if (t.front() == 'B') {
		std::string temp = t;
		std::reverse(temp.begin(), temp.end());
		temp.pop_back();
		Solve(temp);
	}

	// t의 맨 뒤 문자가 A인 경우, 즉 S'A이므로 1번 연산을 반대로 수행함
	if (t.back() == 'A') {
		std::string temp = t;
		temp.pop_back();
		Solve(temp);
	}
}

int main() {
	std::cin >> S >> T;
	Solve(T);

	std::cout << isPossible ? 1 : 0;
	return 0;
}