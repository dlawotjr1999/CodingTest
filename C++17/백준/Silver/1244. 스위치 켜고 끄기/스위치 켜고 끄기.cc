#include <iostream>
#include <vector>

int main() {
	int N;
	std::cin >> N;

	std::vector<bool> switches;
	for (int i = 0; i < N; ++i) {
		bool elm;
		std::cin >> elm;
		switches.push_back(elm);
	}

	int cmd_num;
	std::cin >> cmd_num;

	for (int i = 0; i < cmd_num; ++i) {
		int a, b;
		std::cin >> a >> b;

		if (a == 1) {
			for (int j =  b - 1; j < N; j += b) {
				switches[j] = !switches[j];
			}
		}
		else {
			int idx = b - 1;
			switches[idx] = !switches[idx];

			int l = idx - 1, r = idx + 1;
			while (l >= 0 && r < N && switches[l] == switches[r]) {
				switches[l] = !switches[l];
				switches[r] = !switches[r];
				l--;
				r++;
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		std::cout << switches[i];
		if ((i + 1) % 20 == 0 || i == N - 1) {
			std::cout << '\n';
		}
		else {
			std::cout << ' ';
		}
	}


	return 0;
}