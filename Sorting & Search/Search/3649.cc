#include <iostream>
#include <vector>
#include <algorithm>

// 학교 숙제로 로봇을 만들고 있으며, 로봇을 만들던 중에 구멍을 막을 두 레고 조각이 필요해짐
// 구멍에 넣을 두 조각의 길이의 합은 구멍의 너비와 정확하게 일치해야 하며, 그렇지 않을 경우 시연 시 로봇은 부숴질 것임
// 또한 구멍은 항상 두 조각으로 막아야 함
// 이 때, 구멍을 완벽히 막을 수 있는 두 조각들을 구하는 문제

int main() {
	long long x;

	while (std::cin >> x) {
		long long n;	
		std::cin >> n;

		std::vector<long long> vec(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> vec[i];
		}

		// 이분 탐색을 위해 정렬 수행
		std::sort(vec.begin(), vec.end());

		// nm -> cm 단위 보정
		long long len = x * 10000000;
		bool isOK = false;

		int l = 0, r = n - 1;

		// 서로 다른 두 조각이 사용되어야 하므로 l < r로 조건식 설정
		while (l < r) {
			long long l_val = vec[l], r_val = vec[r];

			// 막고자 하는 길이와 동일한 경우, 두 길이의 차이의 절댓값이 큰 숫자들이 정답이므로 바로 break
			if (l_val + r_val == len) {
				printf("yes %lld %lld\n", l_val, r_val);
				isOK = true;
				break;
			}

			// 막고자 하는 길이보다 짧으면, 짧은 조각의 길이를 늘림
			// 반대의 경우, 긴 조각의 길이를 줄임
			else if (l_val + r_val < len)
				l++;
			else
				r--;
		}

		// 구멍을 완벽히 막을 수 없는 경우
		if(!isOK)
			printf("danger\n");
	}
}