#include <bits/stdc++.h>

std::string str;
std::string answer;
int N;
int seq;

bool visited[11];

void DFS(std::string cur, int len) {
	if (len == str.length()) {
		seq++;
		if (seq == N) {
			answer = cur;
			return;
		}
		return;
	}

	for (int i = 0; i < str.length(); ++i) {
		if(visited[i]) 
			continue;
		visited[i] = true;
		cur += str[i];
		DFS(cur, len + 1);
		cur.pop_back();
		visited[i] = false;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	while(true) {
		std::cin >> str >> N;
		if (std::cin.eof())
			break;

		seq = 0;
		answer.clear();
		memset(visited, false, sizeof(visited));

		DFS("", 0);

		if(seq >= N) 
			std::cout << str << " " << N << " = " << answer << '\n';
		else 
			std::cout << str << " " << N << " = " << "No permutation" << '\n';
	}

	return 0;
}