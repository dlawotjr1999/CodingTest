#include <iostream>
#include <queue>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	int N;	
	std::cin >> N;
	
	while (N--) {
		int num;
		std::cin >> num;
		
		if (num == 0) {
			if (pq.empty())
				std::cout << "0\n";
			else {
				std::cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(num);
		}
	}
	return 0;
}