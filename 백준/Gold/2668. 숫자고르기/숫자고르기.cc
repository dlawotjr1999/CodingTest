#include <bits/stdc++.h>

int arr[101];
bool visited[101];

std::vector<int> answers;

void DFS(int cur, int start) {
	if (visited[cur]) {
		if(cur == start)
			answers.push_back(start);
		return;
	}

	visited[cur] = true;
	DFS(arr[cur], start);
}

int main() {
	int N;	std::cin >> N;

	for (int i = 1; i <= N; ++i) {
		std::cin >> arr[i];
	}

	for (int i = 1; i <= N; ++i) {
		memset(visited, false, sizeof(visited));
		DFS(i, i);
	}

	std::sort(answers.begin(), answers.end());
	std::cout << answers.size() << '\n';

	for (int x : answers) {
		std::cout << x << '\n';
	}

	return 0;
}