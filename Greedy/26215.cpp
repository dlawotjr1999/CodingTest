#include <iostream>
#include <vector>
#include <algorithm>

int cnt;

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec;
	for (int i = 0; i < N; i++) {
		int snow; std::cin >> snow;
		vec.push_back(snow);
	}

	std::sort(vec.rbegin(), vec.rend());
	while (vec[0] > 0) {
		if (N > 1) {
			if (vec[0] > 0)
				vec[0]--;
			if (vec[1] > 0)
				vec[1]--;
		}
		else {
			vec[0]--;
		}
		cnt++;
		std::sort(vec.rbegin(), vec.rend());
	}

	if (cnt > 1440)
		cnt = -1;
	std::cout << cnt;

	return 0;
}