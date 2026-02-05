#include <bits/stdc++.h>

int cnt1_left, cnt2_left;
int cnt1_right, cnt2_right;

int main() {
	int N;	std::cin >> N;

	std::string str = "";
	for (int i = 0; i < N; ++i) {
		char c;	std::cin >> c;
		str += c;
	}

	char base = str[0];
	bool isChanged = false;

	for (int i = 0; i < N; ++i) {
		if (str[i] != base)
			isChanged = true;
		else if (isChanged)
			cnt1_left++;
	}
	for (int i = 0; i < N; ++i) {
		if (str[i] != base)
			cnt2_left++;
	}

	base = str[N - 1];
	isChanged = false;

	for (int i = N - 1; i >= 0; --i) {
		if (str[i] != base)
			isChanged = true;
		else if (isChanged)
			cnt1_right++;
	}
	for (int i = N - 1; i >= 0; --i) {
		if (str[i] != base)
			cnt2_right++;
	}

	std::cout << std::min({cnt1_left, cnt2_left, cnt1_right, cnt2_right});
	return 0;
}