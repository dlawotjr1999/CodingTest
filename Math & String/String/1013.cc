#include <iostream>

// 주어진 문자열들이 정규식 (100+1+ | 01)+을 만족하는지 구하는 문제

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
			// (01)+ 인 경우
			if ((i + 1) < n && str[i] == '0' && str[i + 1] == '1')
				i += 2;

			// 100으로 시작하는 경우
			else if ((i + 2) < n && str[i] == '1' && str[i + 1] == '0' && str[i + 2] == '0') {
				i += 3;

				// 0이 계속될 동안 반복
				// 즉 1이 나올 때까지 0을 셈
				while (i < n && str[i] == '0')
					i++;

				// 100...0인 경우에는 정규식을 만족하지 못함 
				if (i == n || str[i] != '1') {
					isOk = false;
					break;
				}

				// 1이 계속될 동안 반복
				while (i < n && str[i] == '1') {
					i++;

					// (100+1+) 뒤에 다시 (100+1+)이 등장할 수 있음
					// 현재 위치의 1부터 뒤에 00이 존재할 경우 반복 종료
					if ((i + 2) < n && str[i + 1] == '0' && str[i + 2] == '0')
						break;
				}
			}

			// 나머지 경우 모두 정규식을 만족하지 못함
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