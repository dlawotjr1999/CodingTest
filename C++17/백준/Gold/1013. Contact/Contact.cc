#include <iostream>

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		std::string str;
		std::cin >> str;

		bool isOk = true;
		int i = 0;
		int n = str.length();

		while (i < n) {
			if ((i + 1) < n && str[i] == '0' && str[i + 1] == '1')
				i += 2;
			else if ((i + 2) < n && str[i] == '1' && str[i + 1] == '0' && str[i + 2] == '0') {
				i += 3;

				while (i < n && str[i] == '0')
					i++;

				if (i == n || str[i] != '1') {
					isOk = false;
					break;
				}

				while (i < n && str[i] == '1') {
					i++;

					if ((i + 2) < n && str[i + 1] == '0' && str[i + 2] == '0')
						break;
				}
			}
			else {
				isOk = false;
				break;
			}
		}

		if (isOk)
			std::cout << "YES" << '\n';
		else
			std::cout << "NO" << '\n';
	}

	return 0;
}