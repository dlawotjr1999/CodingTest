#include <iostream>
#include <vector>
#include <algorithm>

int answer;

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> mileage;

	while (n--) {
		int p, l;
		std::cin >> p >> l;

		std::vector<int> subject(p);
		for (int i = 0; i < p; ++i) {
			std::cin >> subject[i];
		}
		std::sort(subject.begin(), subject.end());

		if(p < l)
			mileage.push_back(1);
		else
			mileage.push_back(subject[p - l]);
	}

	std::sort(mileage.begin(), mileage.end());
	for (int mil : mileage) {
		m -= mil;
		if (m < 0)
			break;
		answer++;
	}

	std::cout << answer;
	return 0;
}