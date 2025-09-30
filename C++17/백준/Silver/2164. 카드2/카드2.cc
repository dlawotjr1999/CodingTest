#include <iostream>
#include <deque>

int main() {
	int N;	std::cin >> N;
	std::deque<int> dq;

	for (int i = 1; i <= N; ++i) {
		dq.push_back(i);
	}

	while (dq.size() > 1) {
		dq.pop_front();

		int temp = dq.front();
		dq.pop_front();
		dq.push_back(temp);
	}

	std::cout << dq.back();
	return 0;
}