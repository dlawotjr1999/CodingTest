#include <iostream>
#include <vector>
#include <algorithm>

// 전화번호 목록이 일관성을 유지하려면, 한 번호가 다른 번호의 접두어인 경우가 없어야 함
// 전화번호의 목록들을 통해 번호들이 일관성이 있는지 없는지를 구하는 문제

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;
		std::vector<std::string> nums(n);

		for (int i = 0; i < n; ++i) {
			std::cin >> nums[i];
		}

		// 정렬을 수행하면 반드시 접두어와 접두어를 포함한 문자열은 인접하게 됨
		std::sort(nums.begin(), nums.end());
		bool isConsistent = true;

		for (int i = 0; i < n - 1; ++i) {
			// 인접한 두 번호들을 비교함
			// 특정 번호(접두어)가 다음 번호의 첫 번째 위치에 정확히 존재한다면, 다음 번호는 접두어를 가진다는 의미 
			// 전화번호들 목록에 접두어 있는 경우에는 일관성이 존재하지 않음
			if (nums[i + 1].find(nums[i]) == 0) {
				std::cout << "NO\n";
				isConsistent = false;
				break;
			}
		}

		if (isConsistent)
			std::cout << "YES\n";
	}

	return 0;
}