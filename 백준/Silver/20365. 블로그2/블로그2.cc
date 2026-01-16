#include <bits/stdc++.h>	

int main() {
	int N; std::cin >> N;
	
	int r_num = 0, b_num = 0;
	char max_c = 'R';

	std::vector<char> str(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> str[i];
	}

	if (str[0] == 'B')
		b_num++;
	else
		r_num++;

	for (int i = 1; i < str.size(); ++i) {
		if (str[i - 1] == 'R' && str[i] == 'B')
			b_num++;
		else if (str[i - 1] == 'B' && str[i] == 'R')
			r_num++;
	}

	std::cout << std::min(r_num, b_num) + 1;
	return 0;
}