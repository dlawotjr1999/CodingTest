#include <iostream>
#include <stack>

int main() {
	int N;
	int cnt = 1;
	std::cin >> N;

	std::stack<int> space;

	while (N--) {
		int elm;
		std::cin >> elm;

		if (elm == cnt)
			cnt++;
		else
			space.push(elm);

		while (!space.empty() && space.top() == cnt) {
			space.pop();
			cnt++;
		}
	}

	if (space.empty()) {
		std::cout << "Nice";
	}
	else
		std::cout << "Sad";

	return 0;
}