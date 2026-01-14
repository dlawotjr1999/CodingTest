#include <bits/stdc++.h>

// 마법사가 각 머글들과의 약속 시간보다 빨리 혹은 늦게 도착할 수 있음
// 그래서 각 머글들과의 약속을 기다리는 시간을 최소화하기 위해 시간을 T씩 미루고자 함
// 약속 시간이 A_i, 도착 시간이 B_i일 때 약속 시간을 T만큼 미루면 그 합은 |A_i + T - B_i|가 됨
// 이 때, 기다리는 시간의 합이 최소가 되는 서로 다른 정수 T의 갯수를 구하는 문제

int answer;

int main() {
	int N;
	std::cin >> N;

	// 즉 sum(|A_i + T - B_i|)를 최소로 만드는 서로 다른 T의 갯수를 구하는 문제
	// A_i와 B_i의 값은 주어지므로, 절댓값 기호 내부는 T에 대한 일차방정식이라 볼 수 있음
	// 각 경우들을 그래프로 그렸을 때, N이 홀수이면 sum(|A_i + T - B_i|)를 최소로 만드는 값은 단 하나임
	// N이 짝수인 경우에는 정렬된 배열에서 ((N / 2) - 1)번째 인덱스의 값부터 (N / 2)번째 인덱스의 값까지의 갯수임

	std::vector<long long> vec;
	for (int i = 0; i < N; i++) {
		long long a, b;
		std::cin >> a >> b;
		vec.push_back(b - a);
	}
	std::sort(vec.begin(), vec.end());

	std::cout << (N % 2 == 1 ? 1 : (vec[N / 2] - vec[N / 2 - 1] + 1));
	return 0;
}