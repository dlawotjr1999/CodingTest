#include <bits/stdc++.h>

int cities[201][201];
std::vector<int> union_vec;
std::vector<int> plans;

int Find(int parent) {
	if (parent == union_vec[parent])
		return parent;
	return union_vec[parent] = Find(union_vec[parent]);
}

void Union(int a, int b) {
	a = Find(a);
	b = Find(b);
	if(a < b)
		union_vec[b] = a;
	else
		union_vec[a] = b;
}

int main() {
	int N, M;
	std::cin >> N;
	std::cin >> M;
	union_vec.resize(N + 1, 0);

	for(int i = 1; i <= N; ++i) {
		union_vec[i] = i;

		for(int j = 1; j <= N; ++j) {
			std::cin >> cities[i][j];
		}	
	}

	for(int i = 0; i < M; ++i) {
		int plan;
		std::cin >> plan;
		plans.push_back(plan);
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			if(cities[i][j] && union_vec[i] != union_vec[j])
				Union(i, j);
		}
	}

	int root = union_vec[plans[0]];
	for (int i = 1; i < M; ++i) {
		if (Find(plans[i]) != root) {
			std::cout << "NO";
			return 0;
		}
	}

	std::cout << "YES";
	return 0;
}