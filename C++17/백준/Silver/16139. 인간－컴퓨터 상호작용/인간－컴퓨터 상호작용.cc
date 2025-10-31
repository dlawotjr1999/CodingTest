#include <iostream>

int counts[26][200001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;	std::cin >> S;
	int q; std::cin >> q;

	counts[S[0] - 'a'][0] = 1;

	for (int i = 1; i < S.size(); ++i) {
		for (int j = 0; j < 26; ++j) {
			counts[j][i] = counts[j][i - 1];
		}
		counts[S[i] - 'a'][i]++;
	}

	for (int i = 0; i < q; ++i) {
		char a; int l, r;
		std::cin >> a >> l >> r;	

		if (l == 0)
			std::cout << counts[a - 'a'][r] << '\n';
		else
			std::cout << counts[a - 'a'][r] - counts[a - 'a'][l - 1] << '\n';
	}

	return 0;
}