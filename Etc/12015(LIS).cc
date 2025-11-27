#include <bits/stdc++.h>

// LIS의 길이를 구하는 문제
// 이분 탐색 기반 LIS 알고리즘으로 O(nlog n) 내에 해결 가능
// 참고 : https://velog.io/@seho100/%EC%B5%9C%EA%B0%95-%EC%A6%9D%EA%B0%80-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4LIS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98

std::vector<int> answer;

int BinarySearch(int k) {
	int l = 0, r = answer.size() - 1;

	while (l < r) {
		int mid = (r - l) / 2;

		if (answer[mid] >= k)
			r = mid;
		else l = mid + 1;
	}

	return r;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}
	answer.push_back(vec.front());

	for (int i = 1; i < N; i++) {
		if (vec[i] > answer.back())
			answer.push_back(vec[i]);
		else {
			int idx = BinarySearch(vec[i]);
			answer[idx] = vec[i];
		}
	}

	std::cout << answer.size();
	return 0;
}