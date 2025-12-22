#include <iostream>

int N;
bool finished;

bool isOk(std::string& cur) {
	int len = cur.length();

	for (int i = 1; i * 2 <= len; ++i) {
		if (cur.substr(len - 2 * i, i) == cur.substr(len - i, i))
			return false;
	}
	return true;
}

void DFS(int len, std::string cur) {
	if (finished)
		return;
	
	if (len == N) {
		std::cout << cur;
		finished = true;
		return;
	}

	for (char c = '1'; c <= '3'; ++c) {
		cur.push_back(c);
		if (isOk(cur))
			DFS(len + 1, cur);
		cur.pop_back();
	}
}

int main() {
	std::cin >> N;
	DFS(1, "1");

	return 0;
}