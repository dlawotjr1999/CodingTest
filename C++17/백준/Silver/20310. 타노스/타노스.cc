#include <bits/stdc++.h>

int main() {
	std::string S;
	std::cin >> S;

	int zero_cnt = 0, one_cnt = 0;

	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == '0')
			zero_cnt++;
		else
			one_cnt++;
	}

	zero_cnt /= 2, one_cnt /= 2;
	int zero_idx = 0, one_idx = 0;

	std::string temp = "";
	for (char c : S) {
		if (c == '1' && one_idx < one_cnt) {
			one_idx++;
		}
		else
			temp.push_back(c);
	}

	std::string answer = "";
	for (int i = temp.length() - 1; i >= 0; --i) {
		char c = temp[i];
		if (c == '0' && zero_idx < zero_cnt) {
			zero_idx++;
		}
		else
			answer.push_back(c);
	}
	std::reverse(answer.begin(), answer.end());

	std::cout << answer;
	return 0;
}