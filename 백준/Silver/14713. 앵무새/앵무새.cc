#include <bits/stdc++.h>

int main() {
	int N;	std::cin >> N;
	std::cin.ignore();

	std::vector<std::queue<std::string>> parrots(N);

	for (int i = 0; i < N; ++i) {
		std::string str;
		getline(std::cin, str);

		std::stringstream ss(str);
		std::string word;

		while (ss >> word) {
			parrots[i].push(word);
		}
	}

	std::string comp;
	getline(std::cin, comp);

	std::stringstream ss(comp);
	std::string word;

	while (ss >> word) {
		bool isPossible = false;

		for (int i = 0; i < N; ++i) {
			if (!parrots[i].empty() && parrots[i].front() == word) {
				parrots[i].pop();
				isPossible = true;
				break;
			}
		}

		if (!isPossible) {
			std::cout << "Impossible";
			return 0;
		}
	}

	for (int i = 0; i < N; ++i) {
		if (!parrots[i].empty()) {
			std::cout << "Impossible";
			return 0;
		}
	}

	std::cout << "Possible";
	return 0;

}