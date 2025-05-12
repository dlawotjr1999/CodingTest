#include <iostream>
#include <vector>

// 기본적인 Union-Find 구현 문제 

int n, m;

std::vector<int> parent;
std::vector<int> rank_arr;

int Find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int parent_x = Find(x);
	int parent_y = Find(y);

	if (parent_x > parent_y)
		parent[parent_x] = parent_y;
	else
		parent[parent_y] = parent_x;
}

int main() {
	std::ios_base::sync_with_stdio(0);;
	std::cin.tie(0);

	std::cin >> n >> m;

	parent.resize(n + 1);

	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int command, a, b;

		std::cin >> command >> a >> b;
		
		if (command == 0) {
			Union(a, b);
		}
		else {
			if (Find(a) == Find(b))
				std::cout << "YES\n";
			else
				std::cout << "NO\n";
		}
	}

	return 0;
}