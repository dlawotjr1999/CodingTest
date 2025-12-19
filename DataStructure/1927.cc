#include <iostream>
#include <queue>

// 최소 힙을 사용하여 배열에 자연수를 넣는 연산과, 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거하는 연산을 구현하는 문제

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	int N;	
	std::cin >> N;
	
	while (N--) {
		int num;
		std::cin >> num;
		
		// 0을 입력했을 때 pq가 비어있으면 0을, 그렇지 않은 경우 가장 작은 값을 출력하고 pop
		if (num == 0) {
			if (pq.empty())
				std::cout << "0\n";
			else {
				std::cout << pq.top() << '\n';
				pq.pop();
			}
		}
		// 0이 아닌 값을 입력했을 때는 push
		else {
			pq.push(num);
		}
	}
	return 0;
}