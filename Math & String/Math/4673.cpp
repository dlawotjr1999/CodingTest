#include <iostream>
#include <vector>

// 셀프 넘버 구하기
// 참조 : https://www.acmicpc.net/problem/4673

int main() {
	std::vector<bool> vec(10001, true);

	for (int i = 1; i < vec.size(); i++) {
		int sum = 0;
		int num = i;

		while (num != 0) {
			sum += num % 10;
			num /= 10;
		}

		// num은 자릿수를 계산하기 위해 사용되므로 sum + i를 이용
		// sum + i는 (원래 수 + 각 자릿수)를 의미함
		if (sum + i < vec.size()) {
			vec[sum + i] = false;
		}
	}
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] == true)
			std::cout << i << std::endl;
	}
}