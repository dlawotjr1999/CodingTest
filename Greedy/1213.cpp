#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// 팰린드롬 만들기. 정답이 여러 개인 경우 사전 식으로 출력한다
// 팰린드롬의 조건 : 문자들 중 단 한 종류의 문자열만 홀수 개로 이루어져 있고, 나머지 문자열은 짝수 개로 이루어져 있어야만 한다.
// 사전식 출력이기 때문에 입력된 문자열의 정렬이 선행되어야 한다

int main() {
	std::string input;

	std::map<char, int> map;
	int odd_cnt = 0;

	std::cin >> input;
	std::sort(input.begin(), input.end());

	for (int i = 0; i < input.length(); i++) {
		map[input[i]]++;
	}

	// 홀수 개로 이루어진 문자열을 찾는다
	for (auto& elm : map) {
		if (elm.second % 2 == 1) {
			odd_cnt++;
		}
	}

	// 홀수 개로 이루어진 문자열이 두 개 이상이면 팰린드롬을 만들 수 없다
	if (odd_cnt > 1) {
		std::cout << "I'm Sorry Hansoo";
		return 0;
	}

	// 투 포인터를 응용하여 팰린드롬을 구성한다
	int n = input.length();
	std::vector<char> result(n);
	int left = 0, right = n - 1;

	for (auto& elm : map) {
		char c = elm.first;

		while (map[c] > 1) {
			result[left] = c;
			result[right] = c;
			map[c] -= 2;
			left++;
			right--;
		}
	}
	
	// 홀수 개의 문자로 이루어진 문자열의 경우 중간 위치에 남은 한 개의 문자를 위치시킨다
	if (n % 2 == 1) {
		for (auto& elm : map) {
			if (elm.second == 1) {
				result[n / 2] = elm.first;
				break;
			}
		}
	}

	for (char c : result)
		std::cout << c;

	return 0;
}