#include <bits/stdc++.h>

bool isWin(const std::string& str, char c) {
	for (int i = 0; i < 9; i += 3) {
			if (str[i] == c && str[i] == str[i + 1] && str[i + 1] == str[i + 2]) {
				return true;
			}
	}

	for (int i = 0; i < 3; ++i) {
		if (str[i] == 'O' || str[i] == 'X') {
			if (str[i] == c && str[i] == str[i + 3] && str[i + 3] == str[i + 6]) {
				return true;
			}
		}
	}

	if ((str[0] == c && str[0] == str[4] && str[4] == str[8]) || (str[2] == c && str[2] == str[4] && str[4] == str[6])) {
		return true;
	}

	return false;
}

int main() {

	while (true) {
		std::string str;
		std::cin >> str;

		if (str == "end") 
			break;
	
		int o_cnt = 0;
		int x_cnt = 0;

		for (int i = 0; i < str.length(); ++i) {
			if (str[i] == 'O')
				o_cnt++;
			else if (str[i] == 'X')
				x_cnt++;
		}

		bool o_win = isWin(str, 'O');
		bool x_win = isWin(str, 'X');

		if (x_win && !o_win && x_cnt == o_cnt + 1)
			std::cout << "valid";
		else if (o_win && !x_win && o_cnt == x_cnt)
			std::cout << "valid";
		else if (!o_win && !x_win && (o_cnt == 4 && x_cnt == 5))
			std::cout << "valid";
		else
			std::cout << "invalid";
		
		std::cout << '\n';
	}

	return 0;
}