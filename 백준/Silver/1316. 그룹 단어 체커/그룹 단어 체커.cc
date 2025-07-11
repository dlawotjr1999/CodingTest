#include <iostream>
#include <algorithm>

int cnt;

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		bool is_group = true;
		bool alphabet[26];
		std::fill_n(alphabet, 26, false);

		std::string input;
		std::cin >> input;

		int j = 1;

		alphabet[input[0] - 'a'] = true;
		for (; j < input.size(); ++j) {
			if (alphabet[input[j] - 'a'] == true && input[j - 1] != input[j]) {
				is_group = false;
			}
			alphabet[input[j] - 'a'] = true;
		}

		if (is_group)
			cnt++;
	}

	std::cout << cnt;
	return 0;
}