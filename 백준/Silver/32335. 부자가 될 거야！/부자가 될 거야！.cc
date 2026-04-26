#include <bits/stdc++.h>

int main() {
	int N, M;
	std::cin >> N >> M;

	std::string pwd = "";
	for (int i = 0; i < N; ++i) {
		char c;	std::cin >> c;
		pwd += c;
	}

	// sol) 앞에서부터 0을 많이 만들기
	for (int i = 0; i < pwd.length() - 1; ++i) {
		int cur = pwd[i] - '0';
		
		if (cur == 0)
			continue;

		if (cur + M >= 10) {
			pwd[i] = '0';
			M -= (10 - cur);
		}
	}

	int last = pwd.back() - '0';
	pwd.back() = (char)((last + M) % 10 + '0');

	std::cout << pwd;
	return 0;
}