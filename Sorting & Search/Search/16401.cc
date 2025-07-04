#include <iostream>
#include <vector>
#include <algorithm>

// N개의 막대 과자가 존재하며, 이 막대 과자를 M명의 인원들에게 분배하려고 함
// 과자 조각을 나눠줄 때 각 조각은 같은 길이를 가져야 하고, 하나의 과자는 여러 조각으로 나눌 수 있음
// 이 때, 과자 조각이 가질 수 있는 최대 길이를 구하는 문제

int main() {
	int M, N;
	std::cin >> M >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// 탐색 범위는 과자를 가장 작은 크기로 조각내는 경우(1)과 가장 긴 과자의 길이로 설정함
	int left = 1, right = *std::max_element(vec.begin(), vec.end());
	int answer = 0;
	
	while (left <= right) {
		int mid = (left + right) / 2; 
		int count = 0;

		// 전체 과자들에 대해서 탐색
		// 선택된 길이(mid)보다 작은 길이의 과자들은 나눠줄 수 없음
		// 하지만 mid보다 긴 과자는 나눠줄 수 있고, 그 값들의 합(나눠줄 수 있는 인원 수)을 구함
		for (int i = 0; i < N; i++) {
			count += vec[i] / mid; 
		}
		// 인원수(M)보다 count가 클 경우, 과자를 더 길게 자를 수 있다는 의미이므로 left 증가 
		if (count >= M) {
			left = mid + 1;
			answer = mid;
		}
		// 인원수보다 count가 작을 경우, 과자를 더 짧게 잘라야 한다는 의미이므로 right 감소
		else if (count < M) { 
			right = mid - 1;
		}
	}
	std::cout << answer << "\n";

	return 0;
}