#include <iostream>
#include <vector>
#include <cstring>

bool visited[13];

void DFS(std::vector<int>& vec, std::vector<int>& comb, int idx, int cnt) {
	if (cnt == 6) {
		for (int num : comb) {
			std::cout << num << ' ';
		}
		std::cout << '\n';
		return;
	}

	if (idx >= vec.size()) 
		return;

	for (int i = idx; i < vec.size(); ++i) {
		visited[i] = true;
		comb[cnt] = vec[i];
		DFS(vec, comb, i + 1, cnt + 1);
		visited[i] = false;
	}
}

int main() {

	while (true) {
		int k;
		std::cin >> k;

		if (k == 0)
			break;

		memset(visited, false, sizeof(visited));

		std::vector<int> vec(k);
		for (int i = 0; i < vec.size(); ++i) {
			std::cin >> vec[i];
		}
		
		std::vector<int> comb(6);
		DFS(vec, comb, 0, 0);
		std::cout << '\n';
	}

	return 0;
}