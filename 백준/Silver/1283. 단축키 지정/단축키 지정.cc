#include <bits/stdc++.h>

bool alphabet[26];

int main() {
	int N;
	std::cin >> N;

	std::vector<std::string> commands(N);

	std::cin.ignore();
	for (int i = 0; i < N; ++i) {
		std::getline(std::cin, commands[i]);
	}

	for (int i = 0; i < N; ++i) {
		std::string& command = commands[i];
		std::vector<int> idx_vec;

		if (!command.empty())
			idx_vec.push_back(0);
		for (int i = 0; i < command.size(); ++i) {
			if (command[i] == ' ' && i + 1 < command.size())
				idx_vec.push_back(i + 1);
		}
		bool is_checked = false;

		for (int idx : idx_vec) {
			char lower_c = tolower(command[idx]);

			if (!alphabet[lower_c - 'a']) {
				command.insert(idx, "[");
				command.insert(idx + 2, "]");
				alphabet[lower_c - 'a'] = true;
				is_checked = true;
				break;
			}
		}

		if (!is_checked) {
			for (int j = 0; j < command.size(); ++j) {
				if (!isalpha(command[j]))
					continue;
				char lower_c = tolower(command[j]);

				if (!alphabet[lower_c - 'a']) {
					command.insert(j, "[");
					command.insert(j + 2, "]");
					alphabet[lower_c - 'a'] = true;
					break;
				}
			}
		}
	}

	for (const std::string& command : commands) {
		std::cout << command << '\n';
	}

	return 0;
}