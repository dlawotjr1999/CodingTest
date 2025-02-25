#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// Greedy
int main() {
	std::string input;

	std::map<char, int> map;
	int odd_cnt = 0;

	std::cin >> input;
	std::sort(input.begin(), input.end());

	for (int i = 0; i < input.length(); i++) {
		map[input[i]]++;
	}
	for (auto& elm : map) {
		if (elm.second % 2 == 1) {
			odd_cnt++;
		}
	}
	if (odd_cnt > 1) {
		std::cout << "I'm Sorry Hansoo";
		return 0;
	}

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