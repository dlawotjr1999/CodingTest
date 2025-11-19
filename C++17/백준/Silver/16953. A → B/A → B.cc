#include <iostream>
#include <climits>
#include <queue>

int BFS(int a, int b) {
	std::queue<std::pair<long long, int>> q;
	q.emplace(a, 0);

	while (!q.empty()) {
		auto [cur_num, op_num] = q.front();
		q.pop();

		if (cur_num == b)
			return op_num + 1;
		else if (cur_num > INT_MAX)
			continue;
		else {
			long long mul2 = cur_num * 2;
			long long add1 = cur_num * 10 + 1;

			if (mul2 < INT_MAX)
				q.emplace(mul2, op_num + 1);
			if (add1 < INT_MAX)
				q.emplace(add1, op_num + 1);
		}
	}

	return -1;
}

int main() {
	int A, B;
	std::cin >> A >> B;

	std::cout << BFS(A, B);
	return 0;
}