#include <bits/stdc++.h>

std::vector<std::string> field(3);
std::vector<std::string> vec(6);

bool visited[6];
bool isFound = false;

bool CheckWord() {
	std::vector<std::string> temp;

	for (int i = 0; i < 3; ++i) {
		std::string str1 = "";
		std::string str2 = "";

		for (int j = 0; j < 3; ++j) {
			str1 += field[i][j];
			str2 += field[j][i];
		}

		temp.push_back(str1);
		temp.push_back(str2);
	}
	std::sort(temp.begin(), temp.end());

	return vec == temp;
}

void DFS(int cnt) {
	if (isFound)
		return;

	if (cnt == 3) {
		if (CheckWord()) {
			isFound = true;
			for (int i = 0; i < 3; ++i)
				std::cout << field[i] << '\n';
		}
		return;
	}

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

	DFS(0);

	if(!isFound)
		std::cout << 0;
	return 0;
}