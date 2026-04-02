#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	int T;	cin >> T;

	while (T--) {
		unordered_map<char, int> m;
		bool isPossible = false;

		string str;	cin >> str;
		for (int i = 0; i < str.length(); ++i) {
			m[str[i]]++;
		}
		m[str.back()]++;

		int n = m['N'];	int w = m['W'];	int s = m['S'];	int e = m['E'];

		if (n != 0 && w != 0 && s != 0 && e != 0
			|| n != 0 && w == 0 && s != 0 && e == 0
			|| n == 0 && w != 0 && s == 0 && e != 0)
				isPossible = true;

		cout << (isPossible ? "Yes" : "No") << '\n';
	}

	return 0;
}