#include <bits/stdc++.h>

int answer;

int main() {
	std::string input; 
	std::cin >> input;

	int len = 0;
	int cnt = 0;

	for (int i = 0; i < input.length(); ++i) {
		if (input[i] == 'a') len++;
	}

	for (int i = 0; i < len; ++i) {
		if (input[i] == 'b') cnt++;
	}
	
	answer = cnt;
	for (int i = len; i < len + input.length(); ++i) {
		if (input[i % input.length()] == 'b') cnt++;
		if (input[(i - len) % input.length()] == 'b') cnt--;
		answer = std::min(answer, cnt);
	}

	std::cout << answer;
	return 0;
}