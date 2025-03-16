#include <iostream>
#include <string>
#include <map>

// map을 활용하는 문제
// 문자열을 입력하면 문자열에 맞는 숫자를, 숫자를 입력하면 그에 맞는 문자열을 출력해야 함 

int N, M;
std::map<std::string, int> map;
std::string ary[100001];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		std::string name;
		std::cin >> name;
		map.emplace(name, i);
		ary[i] = name;
	}

	for (int i = 0; i < M; i++) {
		std::string input;
		std::cin >> input;

		// 입력값이 숫자인 경우 배열에서 key에 맞는 value(string)을 출력
		// NOTE : stoi 함수 -> string을 int형으로 변환
		if (std::isdigit(input[0])) {
			std::cout << ary[stoi(input)] << '\n';
		}
		// 반대인 경우는 입력값이 string이므로 value에 해당하는 숫자 출력
		else {
			std::cout << map.find(input)->second << '\n';
		}
	}
}