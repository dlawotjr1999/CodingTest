#include <bits/stdc++.h>

// 한 술집에서 막걸리를 주문하면 주전자의 용량은 똑같았으나 안에 들어 있는 막걸리 용량은 랜덤임
// 또한 다른 주전자의 막걸리가 섞이는 것이 싫어서, 분배 후 주전자에 막걸리가 조금 남아 있다면 그냥 막걸리를 버리기로 함
// 이때, K명에게 최대한의 많은 양의 막걸리를 분배할 수 있는 용량을 구하는 문제

long long answer;

int main() {
	int N, K;
	std::cin >> N >> K;

	long long l = 1;

	std::vector<long long> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	int r = *max_element(vec.begin(), vec.end());

	// 막걸리의 용량을 이분 탐색으로 진행
	// 가장 적은 양으로 나누는 경우(l)과 가장 많은 양으로 나누는 경우(r)를 시작으로 하여 이분탐색 진행
	while (l <= r) {
		long long mid = (l + r) / 2;
		long long cnt = 0;

		// 용량만큼 나눈 후 남은 막걸리는 모두 버리므로 몫만을 취함 
		for(int i = 0; i < vec.size(); ++i) {
			cnt += vec[i] / mid;
		}
		
		// K명보다 더 많은 사람에게 나눌 수 있는 경우 용량 증가
		if (cnt >= K) {
			answer = mid;
			l = mid + 1;
		}

		// K명보다 더 적은 사람에게 나누어 지는 경우 용량 감소
		else if(cnt < K) {
			r = mid - 1;
		}
	}

	std::cout << answer;
	return 0;
}