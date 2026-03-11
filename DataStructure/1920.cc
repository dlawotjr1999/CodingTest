#include <iostream>
#include <unordered_set>

// N개의 정수가 주어져 있을 때, 이 안에 X라는 정수가 존재하는지 구하는 문제

int answer;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int N; std::cin >> N;
	std::unordered_set<int> s(N);

	while (N--) {
		int n; std::cin >> n;
		s.insert(n);
	}

	// set을 사용하면 검색 시 평균 O(1)의 시간복잡도가 적용됨
	int M;	std::cin >> M;
	while (M--) {
		int m; std::cin >> m;
		std::cout << (s.count(m) ? 1 : 0) << '\n';
	}
}