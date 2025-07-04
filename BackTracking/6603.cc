#include <iostream>
#include <vector>
#include <cstring>

// 독일 로또에서, 주어진 집합 S의 수들로 가능한 조합의 경우의 수를 구하는 문제

bool visited[13];

void DFS(std::vector<int>& vec, std::vector<int>& comb, int idx, int cnt) {
	// 뽑은 횟수가 6이면 6가지 수로 이루어진 하나의 경우의 수 출력
	if (cnt == 6) {
		for (int num : comb) {
			std::cout << num << ' ';
		}
		std::cout << '\n';
		return;
	}

	// 인덱스가 S의 크기를 넘어도 종료
	if (idx >= vec.size()) 
		return;


	for (int i = idx; i < vec.size(); ++i) {
		// 현재 뽑은 수를 comb에 하나씩 저장
		comb[cnt] = vec[i];
		DFS(vec, comb, i + 1, cnt + 1);
	}
}

int main() {

	while (true) {
		int k;
		std::cin >> k;

		if (k == 0)
			break;

		memset(visited, false, sizeof(visited));

		std::vector<int> vec(k);
		for (int i = 0; i < vec.size(); ++i) {
			std::cin >> vec[i];
		}
		
		std::vector<int> comb(6);
		// 집합 S, 가능한 조합, 인덱스, 뽑은 횟수
		DFS(vec, comb, 0, 0);
		std::cout << '\n';
	}

	return 0;
}