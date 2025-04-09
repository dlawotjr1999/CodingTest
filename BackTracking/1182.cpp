#include <iostream>
#include <vector>

int N, S;
int cnt;

std::vector<int> vec;

void DFS(int depth, int sum) {
	if (depth == N) {
		if (sum == S) {
			cnt++;
		}
		return;
	}

	DFS(depth + 1, sum);
	DFS(depth + 1, sum + vec[depth]);
}

int main() {
	std::cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int elm; std::cin >> elm;
		vec.push_back(elm);
	}
	
	DFS(0, 0);

	if (S == 0)
		cnt--;
	std::cout << cnt;

	return 0;
}