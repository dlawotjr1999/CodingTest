#include <iostream>
#include <vector>
#include <deque>

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int& elm : vec) {
		std::cin >> elm;
	}

	std::deque<int> queuestack;
	for (int i = 0; i < N; i++) {
		int elm;
		std::cin >> elm;

		if (vec[i] == 0)
			queuestack.push_back(elm);
	}

	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int elm;
		std::cin >> elm;
		queuestack.push_front(elm);
		std::cout << queuestack.back() << " ";
		queuestack.pop_back();
	}

	return 0;
}