#include <iostream>

// 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것이 있으면 그 수열을 나쁜 수열이라고 부르며, 그렇지 않은 수열은 좋은 수열이라 함
// 이 때, 숫자 1,2,3으로만 이루어진 수열 중 길이가 N인 가장 작은 수를 나타내는 좋은 수열을 구하는 문제

int N;
bool finished;

// pruning; 엄격한 pruning을 통해 N이 최대 80임에도 backtracking이 가능함
// 새로 추가된 문자로 인해 생길 수 있는 문제를 검토해야므로, 문자열의 끝에서부터 좋은 수열의 규칙에 부합하는지를 검토
bool isOk(std::string& cur) {
	int len = cur.length();

	for (int i = 1; i * 2 <= len; ++i) {
		if (cur.substr(len - 2 * i, i) == cur.substr(len - i, i))
			return false;
	}
	return true;
}

void DFS(int len, std::string cur) {
	// finished 플래그를 통해 첫 번째로 만들어지는, 즉 가장 작은 수열만을 출력하도록 함
	if (finished)
		return;
	
	if (len == N) {
		std::cout << cur;
		finished = true;
		return;
	}

	// 1,2,3으로만 이루어져 있으므로 이들로만 완전탐색 진행
	for (char c = '1'; c <= '3'; ++c) {
		cur.push_back(c);
		if (isOk(cur))
			DFS(len + 1, cur);
		cur.pop_back();
	}
}

int main() {
	std::cin >> N;

	// 가장 작은 수열을 구하는 것이므로 1로 시작하는 수열로 고정하여 시작
	DFS(1, "1");

	return 0;
}