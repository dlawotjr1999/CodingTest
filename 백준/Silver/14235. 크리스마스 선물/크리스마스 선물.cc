#include <bits/stdc++.h>

int main() {
	int n; std::cin >> n;
	std::priority_queue<int> pq;

	for (int i = 0; i < n; ++i) {
		int a; std::cin >> a;

		if (a != 0) {
			for (int j = 0; j < a; ++j) {
				int x; std::cin >> x;
				pq.push(x);
			}
		}
		else {
			if (pq.empty())
				std::cout << -1 << '\n';
			else {
				std::cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}

	return 0;
}