#include <iostream>

using namespace std;

int MaxLength(string& str, int l, int r) {
	while (l >= 0 && r < str.length() && str[l] == str[r]) {
		l--;
		r++;
	}

	return r - l - 1;
}

int main() {
	int T;	cin >> T;

	for (int test_case = 1; test_case <= T; ++test_case) {
		string str;	cin >> str;
		int answer = 0;

		for (int i = 0; i < str.length(); ++i) {
			answer = max(answer, MaxLength(str, i, i));
			answer = max(answer, MaxLength(str, i, i + 1));
		}

		cout << "#" << test_case << " ";
		cout << answer << '\n';
	}
}