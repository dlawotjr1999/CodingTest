#include <iostream>
#include <vector>
#include <set>

int N;
int answer = 1;

std::vector<int> vec;
std::vector<bool> visited(2000001);

void DFS(int idx, int cur) {
	if (idx == N) {
		visited[cur] = true;
		return;
	}

	DFS(idx + 1, cur);
	DFS(idx + 1, cur + vec[idx]);
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	vec.resize(N);

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	DFS(0, 0);

	while (visited[answer])
		answer++;

	std::cout << answer;
	return 0;
}