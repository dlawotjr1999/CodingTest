#include <bits/stdc++.h>

int min = 1e9;
int max = -1e9;

int N;
std::vector<int> vec;
int ary[4];

void DFS(int result, int cnt) {
	if (cnt == N - 1) {
		if (result > max)
			max = result;
		if (result < min) {
			min = result;
		}
		return;
	}

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

	DFS(vec[0], 0);

	std::cout << max << '\n' << min;
	return 0;
}