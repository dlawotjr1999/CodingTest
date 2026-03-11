#include <bits/stdc++.h>

// 6개의 단어로 3*3 가로 세로 퍼즐을 만들 때, 가능한 답을 구하는 문제
// 가능한 답이 여러 개면 사전 순으로 앞서는 것을 출력하며, 불가능할 경우에는 0 출력

std::vector<std::string> field(3);
std::vector<std::string> vec(6);

bool visited[6];
bool isFound = false;

// field에 있는 6개의 문자열들이 입력된 문자열들과 일치하는지 판별하는 함수
bool CheckWord() {
	std::vector<std::string> temp;

	for (int i = 0; i < 3; ++i) {
		std::string str1 = "";
		std::string str2 = "";

		// str1 : 가로로 만들어진 문자열
		// str2 : 세로로 만들어진 문자열
		for (int j = 0; j < 3; ++j) {
			str1 += field[i][j];
			str2 += field[j][i];
		}

		temp.push_back(str1);
		temp.push_back(str2);
	}

	// 입력된 문자열들, 즉 vec의 원소들은 이미 정렬되어 있음
	// 비교를 위해 field의 문자열들도 모두 정렬 수행
	std::sort(temp.begin(), temp.end());

	// 입력된 문자열들과 현재 field의 모든 문자열들이 일치하면 올바른 가로 세로 퍼즐
	return vec == temp;
}

// 주어진 단어들로 만들 수 있는 순열 backtracking
void DFS(int cnt) {
	// 조건을 만족하는 경우를 찾으면 종료
	// isFound로 검사를 했기 때문에 가장 먼저 나오는 것 하나만 정답이 됨(여러 개인 경우 사전순으로 정렬되어야 하기 때문)
	if (isFound)
		return;

	// 3개의 단어 쌍들이 만들어졌을 때, 그것이 가로 세로 퍼즐의 단어들과 일치하면 성공
	// 가로 세로 퍼즐의 조건에 부합하면 하나씩 출력
	if (cnt == 3) {
		if (CheckWord()) {
			isFound = true;
			for (int i = 0; i < 3; ++i)
				std::cout << field[i] << '\n';
		}
		return;
	}

	// 6개의 단어들로 만들 수 있는 모든 경우의 수 탐색
	for (int i = 0; i < 6; ++i) {
		if (!visited[i]) {
			visited[i] = true;
			field[cnt] = vec[i];
			DFS(cnt + 1);
			visited[i] = false;
		}
	}
}

int main() {
	for (int i = 0; i < vec.size(); ++i) {
		std::cin >> vec[i];
	}

	// 단어쌍의 갯수를 인자로 backtracking 진행
	DFS(0);

	if(!isFound)
		std::cout << 0;
	return 0;
}