#include <bits/stdc++.h>

// 주어진 순열에 정해진만큼의 연산자들을 끼워넣어서 만들 수 있는 최솟값, 최댓값을 구하는 문제

int min = 1e9;
int max = -1e9;

int N;
std::vector<int> vec;
int ary[4];	// +, -, *, /

void DFS(int result, int cnt) {
	// 총 연산자의 갯수(N - 1)만큼 탐색이 되면 종료
	if (cnt == N - 1) {
		if (result > max)
			max = result;
		if (result < min) {
			min = result;
		}
		return;
	}

	// 연산자들을 탐색하며 다음 항과 계산 진행
	for (int i = 0; i < 4; ++i) {
		if (ary[i] != 0) {
			ary[i]--;
			if (i == 0) {
				DFS(result + vec[cnt + 1], cnt + 1);
			}
			else if (i == 1) {
				DFS(result - vec[cnt + 1], cnt + 1);
			}
			else if (i == 2) {
				DFS(result * vec[cnt + 1], cnt + 1);
			}
			else {
				DFS(result / vec[cnt + 1], cnt + 1);
			}
			ary[i]++;
		}
	}

}

int main() {
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		int num; std::cin >> num;
		vec.emplace_back(num);
	}

	for (int i = 0; i < 4; ++i) {
		std::cin >> ary[i];
	}

	// 수열의 초항과, 연산자의 갯수를 인자로 하여 탐색 진행
	DFS(vec[0], 0);

	std::cout << max << '\n' << min;
	return 0;
}