#include <iostream>
#include <list>

int main() {
	std::string input; 
	int N;

	std::cin >> input;
	std::cin >> N;

	std::list<char> input_list(input.begin(), input.end());
	auto cursor = input_list.end();

	for (int i = 0; i < N; ++i) {
		char cmd; std::cin >> cmd;
		
		if (cmd == 'L') {
			if (cursor == input_list.begin())
				continue;
			cursor--;
		}
		else if (cmd == 'D') {
			if (cursor == input_list.end())
				continue;
			cursor++;
		}
		else if (cmd == 'B') {
			if (cursor != input_list.begin())
				cursor = input_list.erase(--cursor);
		}
		else if (cmd == 'P') {
			char c;	std::cin >> c;
			input_list.insert(cursor, c);
		}
	}

	for (char c : input_list) std::cout << c;
	std::cout << "\n";

	return 0;
}