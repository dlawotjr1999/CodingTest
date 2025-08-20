#include <bits/stdc++.h>

// 한 문자열로 순열을 구성할 때, 그 순열들 중 주어진 위치(N)의 순열을 구하는 문제

std::string str;
std::string answer;
int N;
int seq;

bool visited[11];

void DFS(std::string cur, int len) {
	// 원래 문장열의 길이가 일치하면 시퀀스 증가
	// 시퀀스를 하나씩 증가시켜 가며 찾고자 하는 N번째 순열 탐색 
	if (len == str.length()) {
		seq++;

		// N번째 순열과 일치할 경우 답으로 선정하고 종료
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

		// 빈 문자열과 그 길이를 매개변수로 하여 탐색 시작
		DFS("", 0);

		if(seq >= N) 
			std::cout << str << " " << N << " = " << answer << '\n';
		else 
			std::cout << str << " " << N << " = " << "No permutation" << '\n';
	}

	return 0;
}