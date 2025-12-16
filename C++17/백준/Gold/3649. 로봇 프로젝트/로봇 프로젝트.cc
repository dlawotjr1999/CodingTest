#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	long long x;

	while (std::cin >> x) {
		long long n;	std::cin >> n;

		std::vector<long long> vec(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> vec[i];
		}
		std::sort(vec.begin(), vec.end());

		int l = 0, r = n - 1;
		long long len = x * 10000000;
		bool isOK = false;

		while (l < r) {
			long long l_val = vec[l], r_val = vec[r];

			if (l_val + r_val == len) {
				printf("yes %lld %lld\n", l_val, r_val);
				isOK = true;
				break;
			}

			else if (l_val + r_val < len)
				l++;
			else
				r--;
		}

		if(!isOK)
			printf("danger\n");
	}
}