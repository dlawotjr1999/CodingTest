#include <iostream>
#include <algorithm>

std::string S, T;
bool isPossible;

void Solve(std::string& t) {
	if (t == S) {
		isPossible = true;
		return;
	}

	if (t.length() < S.length())
		return;
	
	if (t.front() == 'B') {
		std::string temp = t;
		std::reverse(temp.begin(), temp.end());
		temp.pop_back();
		Solve(temp);
	}
	if (t.back() == 'A') {
		std::string temp = t;
		temp.pop_back();
		Solve(temp);
	}
}

int main() {
	std::cin >> S >> T;
	Solve(T);

	std::cout << isPossible ? 1 : 0;
	return 0;
}