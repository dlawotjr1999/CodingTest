#include <iostream>
#include <vector>

// X와 .으로 이루어진 문자열을 AAAA와 BB로 치환하는 문제
// X를 빈틈없이 AAAA와 BB로 덮어야하며, 덮지 못하는 경우는 -1을 출력한다

int main() {
	std::string input;
	std::string result = "";
	int cnt = 0;

	std::cin >> input;

	for (int i = 0; i < input.length(); i++) {
		// . 이전에 있는 X로 이루어져 있는 문자열의 길이를 구함
		if (input[i] != '.') {
			cnt++;
		}
		else {
			// cnt가 홀수이면 폴리오미노들로 덮을 수 없으므로 -1을 출력
			if (cnt % 2 != 0) {
				std::cout << -1;
				return 0;
			}
			// 문자열을 치환하는 과정. 
			// 최대한 AAAA를 활용하며, 마지막에 2개가 남은 경우 BB로 덮는다
			else {
				while (cnt >= 4) {
					result += "AAAA";
					cnt -= 4;
				}
				while (cnt == 2) {
					result += "BB";
					cnt -= 2;
				}
				result += '.';
			}
		}
	}

	// .으로 끝나지 않는 문자열의 경우 남은 문자열을 처리하기 위해 한 번 더 연산을 해야 함
	// .으로 끝나지 않은 경우 위의 반복문에서 cnt를 활용하여 마지막 문자열을 처리한다
	if (cnt % 2 != 0) {
		std::cout << -1;
		return 0;
	}
	else {
		while (cnt >= 4) {
			result += "AAAA";
			cnt -= 4;
		}
		while (cnt == 2) {
			result += "BB";
			cnt -= 2;
		}
	}

	std::cout << result;

	return 0;
}