#include <bits/stdc++.h>

int answer;

int main() {
	std::string str1, str2;
	std::cin >> str1 >> str2;

	std::string piece1, piece2;

	if (str1.length() > str2.length()) { piece1 = str1; piece2 = str2; }
	else { piece1 = str2; piece2 = str1; }
	int long_len = (int)piece1.length();

	std::string temp(piece2.length(), '0');
	piece1 = temp + piece1 + temp;

	answer = str1.length() + str2.length();
	for (size_t i = 0; i <= piece1.length() - piece2.length(); ++i) {
		bool isPossible = true;
		int out_len = 0;

		for (size_t j = 0; j < piece2.length(); ++j) {
			if (piece1[i + j] == '0')
				out_len++;
			else {
				if (piece1[i + j] == '2' && piece2[j] == '2') {
					isPossible = false;
					break;
				}
			}
		}

		if (isPossible)
			answer = std::min(answer, out_len + long_len);
	}

	std::cout << answer;
	return 0;
}