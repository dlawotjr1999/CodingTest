#include <bits/stdc++.h>

std::unordered_map<std::string, std::string> m;
std::unordered_map<std::string, bool> visited;

int idx = 1;
int answer;

void DFS(const std::string& cur) {
	if (visited[m[cur]]) {
		answer++;
	}
	else {
		visited[m[cur]] = true;
		DFS(m[cur]);
	}
}

int main() {
	int T;

	while (std::cin >> T) {
		if (T == 0)
			break;
		
		answer = 0;
		m.clear();
		visited.clear();

		for (int i = 0; i < T; ++i) {
			std::string name1, name2;
			std::cin >> name1 >> name2;
			m[name1] = name2;
		}

		for (auto elm : m) {
			if (visited[elm.first])
				continue;

			DFS(elm.first);
		}

		std::cout << idx << ' ' << answer << '\n';
		idx++;
	}

	return 0;
}