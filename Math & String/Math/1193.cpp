#include <iostream>

// 
int main() {
	int line = 1;
	int x;
	std::cin >> x;

	while (x > line) {
		x -= line;
		line++;
	}

	if (line % 2 == 1)
		std::cout << (line + 1 - x) << '/' << x;
	else
		std::cout << x << '/' << (line + 1 - x);


	return 0;
}