#include <iostream>
#include <vector>

// 부분수열의 합 문제
// N개의 정수로 이루어진 수열이 있을 때, 크기가 양수인 부분수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 문제

int N, S;
int cnt;

std::vector<int> vec;

void DFS(int depth, int sum) {

	// 기저조건 : N개까지 탐색하였을 때 그 합이 S인 경우 갯수 증가
	if (depth == N) {
		if (sum == S) {
			cnt++;
		}
		return;
	}

	DFS(depth + 1, sum);				// 현재 원소를 포함하지 않는 경우
	DFS(depth + 1, sum + vec[depth]);	// 현재 원소를 포함하는 경우
}

int main() {
	std::cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int elm; std::cin >> elm;
		vec.push_back(elm);
	}
	
	DFS(0, 0);

	// 공집합인 경우는 빼준다
	if (S == 0)
		cnt--;
	std::cout << cnt;

	return 0;
}