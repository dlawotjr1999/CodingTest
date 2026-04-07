#include <bits/stdc++.h>

int main() {
	int N;
	std::cin >> N;

	std::priority_queue<double> pq;
	for (int i = 0; i < N; ++i) {
		int n;  std::cin >> n;
		pq.push(n);
	}

	while (pq.size() > 1) {
		double n1 = pq.top();
		pq.pop();

		double n2 = pq.top();
		pq.pop();

		double new_drink = n1 + (n2 / 2);
		pq.push(new_drink);
	}


	std::cout << pq.top();
	return 0;
}