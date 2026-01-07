#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int answer;
bool visited[11][1000000]; 

void DFS(std::string& s, int cnt) {
	int res = stoi(s);
	if (visited[cnt][res])
		return;
	visited[cnt][res] = true;

	if (cnt == 0) {
		answer = std::max(answer, res);
		return;
	}

	for (int i = 0; i < s.length(); ++i) {
		for (int j = i + 1; j < s.length(); ++j) {
			swap(s[i], s[j]);
			DFS(s, cnt - 1);
			swap(s[i], s[j]);
		}
	}
}

int main() {
	int T;	std::cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		std::string str; std::cin >> str;
		int n; std::cin >> n;

		DFS(str, n);
		printf("#%d %d\n", tc, answer);

		answer = 0;
		memset(visited, false, sizeof(visited));
	}
	
	return 0;
}