#include <bits/stdc++.h>

// 자연수들로 이루어진 집합 U가 있을 때, 이 중에서 적당히 세 수를 고르고자 함
// 이때 고른 세 수의 합 d가 U 안에 존재할 수도 있으며, 세 수와 d는 서로 같아도 됨
// 이러한 경우 중에서 가장 큰 d를 찾는 문제

int answer;

// x + y + z = d를 만족하는 경우를 찾을 때 세 수의 조합을 사용하면 시간복잡도는 O(N^3)이 됨
// 즉 x + y = d - z로 식을 변형하여 알고리즘 진행(시간복잡도 : O(N^2))
int main() {
	int N; std::cin >> N;

	std::vector<int> U(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> U[i];
	}

	// (x + y)로 의 값들을 가지는 집합 계산
	std::unordered_set<int> temp;
    temp.reserve(N * N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			temp.insert(U[i] + U[j]);
		}
	}

	// (d - z)의 값 계산 후 판별
	for (int i = 0; i < N; ++i) {
		int cur = U[i];
		for (int j = 0; j < N; ++j) {
			// (d - z)의 값이 temp 집합 내에 속해 있으면, 가장 큰 d값 갱신
			if (temp.find(cur - U[j]) != temp.end())
				answer = std::max(answer, cur);
		}
	}

	std::cout << answer;
	return 0;
}