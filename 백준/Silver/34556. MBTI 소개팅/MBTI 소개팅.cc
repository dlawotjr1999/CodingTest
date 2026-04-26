#include <bits/stdc++.h>

int N;
int answer;

std::vector<std::string> males;
std::vector<std::string> females;

std::vector<bool> visited;

void DFS(int cnt, std::vector<std::string>& cur_males) {
	if (cnt == N) {
		int score = 0;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 4; ++j) {
				if (cur_males[i][j] != females[i][j])
					score++;
			}
		}

		answer = std::max(answer, score);
		return;
	}

	for (int i = 0; i < N; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			cur_males.push_back(males[i]);
			DFS(cnt + 1, cur_males);
			visited[i] = false;
			cur_males.pop_back();
		}
	}
}

int main() {
	std::cin >> N;
	visited.resize(N, false);

	for (int i = 0; i < N; ++i) {
		std::string str; std::cin >> str;
		males.push_back(str);
	}

	for (int i = 0; i < N; ++i) {
		std::string str; std::cin >> str;
		females.push_back(str);
	}

	std::vector<std::string> cur_males;
	DFS(0, cur_males);

	std::cout << answer;
	return 0;
}