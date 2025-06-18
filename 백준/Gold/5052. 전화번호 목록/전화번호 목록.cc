#include <iostream>
#include <vector>
#include <algorithm>

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

		std::sort(nums.begin(), nums.end());
		bool isConsistent = true;

		for (int i = 0; i < n - 1; ++i) {
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