	#include <iostream>
	#include <vector>
	#include <algorithm>

	// 주어진 수열 내 두 숫자의 합과, 입력된 num이 일치하는 갯수를 구하는 문제
	// 투 포인터를 이용하여 구현
	int main() {
		int n;
		int num;
		int cnt = 0;
		std::cin >> n;

		std::vector<int> vec(n);
		for (int i = 0; i < vec.size(); i++) {
			std::cin >> vec[i];
		}
		std::cin >> num;

		std::sort(vec.begin(), vec.end());

		int left = 0, right = n - 1;
		while (left < right) {
			if (vec[left] + vec[right] == num) {
				cnt++;
				left++;
				right--;
			}
			else if (vec[left] + vec[right] > num) {
				right--;
			}
			else {
				left++;
			}
		}
		std::cout << cnt << std::endl;

		return 0;
	}