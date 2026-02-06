#include <bits/stdc++.h>

// 같은 원소가 K개 이하로 들어 있는 최장 연속 부분 수열의 길이를 구하는 문제

int cnt[200001];

int main() {
	int N, K;
	std::cin >> N >> K;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// 수열의 길이를 구하기 위한 자료구조로 deque 사용(양방향으로 연산이 가능하기 때문)
	std::deque<int> dq;
	int answer = 0;

	// 내부에 루프를 사용하지만 시간 복잡도는 O(N)
	// push_back과 pop_front가 반복되어 진행되기 때문
	for (int i = 0; i < N; ++i) {
		// 각 원소들을 dq에 삽입하고 그 원소의 갯수를 증가시킴
		dq.push_back(vec[i]);
		cnt[vec[i]]++;

		// 삽입한 원소의 갯수가 K를 넘을 경우
		// 그 원소의 갯수가 K가 될 때까지 앞에서부터 pop을 한 뒤 삭제되는 원소들의 갯수 감소
		while (cnt[vec[i]] > K) {
			cnt[dq.front()]--;
			dq.pop_front();
		}

		// 매 반복마다 dq의 크기, 즉 수열의 길이의 최댓값 갱신
		answer = std::max(answer, (int)dq.size());
	}

	std::cout << answer;
	return 0;
}