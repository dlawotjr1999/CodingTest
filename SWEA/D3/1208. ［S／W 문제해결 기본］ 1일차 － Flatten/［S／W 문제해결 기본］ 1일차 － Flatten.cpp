#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	for (int tc = 1; tc <= 10; ++tc) {
		int dump; cin >> dump;
		int answer = 0;

		std::vector<int> vec(100);
		for (int i = 0; i < 100; ++i) {
			cin >> vec[i];
		}

		int min_idx = 0, max_idx = 0;
		for (int i = 0; i < dump; ++i) {
			min_idx = min_element(vec.cbegin(), vec.cend()) - vec.cbegin();
			max_idx = max_element(vec.cbegin(), vec.cend()) - vec.cbegin();

			if (vec[max_idx] - vec[min_idx] <= 1)
				break;

			vec[max_idx]--;
			vec[min_idx]++;
		}
		answer = *max_element(vec.cbegin(), vec.cend()) - *min_element(vec.cbegin(), vec.cend());

		printf("#%d %d\n", tc, answer);
	}

	return 0;
}