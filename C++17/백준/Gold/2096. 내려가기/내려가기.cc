#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N;	std::cin >> N;

	int prev_max[3]; int prev_min[3];
	int cur_max[3]; int cur_min[3];

	std::cin >> prev_max[0] >> prev_max[1] >> prev_max[2];

	prev_min[0] = prev_max[0];
	prev_min[1] = prev_max[1];
	prev_min[2] = prev_max[2];

	if (N == 1) {
		std::cout << std::max({ prev_max[0], prev_max[1], prev_max[2] }) << ' '
			<< std::min({ prev_min[0], prev_min[1], prev_min[2] });
		return 0;
	}

	for (int i = 2; i <= N; ++i) {
		int a, b, c;
		std::cin >> a >> b >> c;

		cur_max[0] = std::max(prev_max[0], prev_max[1]) + a;
		cur_max[1] = std::max({ prev_max[0], prev_max[1], prev_max[2] }) + b;
		cur_max[2] = std::max(prev_max[1], prev_max[2]) + c;

		cur_min[0] = std::min(prev_min[0], prev_min[1]) + a;
		cur_min[1] = std::min({ prev_min[0], prev_min[1], prev_min[2] }) + b;
		cur_min[2] = std::min(prev_min[1], prev_min[2]) + c;

		for (int i = 0; i < 3; ++i) {
			prev_max[i] = cur_max[i];
			prev_min[i] = cur_min[i];
		}
	}

	std::cout << std::max({ cur_max[0], cur_max[1], cur_max[2] }) << ' ' << std::min({ cur_min[0], cur_min[1], cur_min[2] });
	return 0;
}