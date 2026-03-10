#include <iostream>
#include <unordered_set>

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

	int M;	std::cin >> M;
	while (M--) {
		int m; std::cin >> m;
		std::cout << (s.count(m) ? 1 : 0) << '\n';
	}
}