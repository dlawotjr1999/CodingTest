#include <iostream>

// 문자열 내 특정 구간에서 특정 알파벳이 몇 번 나타나는지 구하는 문제

// 한 단어에서 각 알파벳이 등장하는 횟수를 저장하는 2차원 배열
// 특정 소문자에 대한 특정 인덱스까지의 등장 횟수를 저장
int counts[26][200001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::string S;	std::cin >> S;
	int q; std::cin >> q;

	counts[S[0] - 'a'][0] = 1;

	// 문자 하나를 검토할 때마다 모든 알파벳을 순회하며 특정 알파벳의 등장횟수 갱신
	// 등장하지 않은 알파벳에 대해서는 이전의 값을 그대로 사용하며, 등장한 알파벳에 대해서는 등장횟수 증가
	for (int i = 1; i < S.size(); ++i) {
		for (int j = 0; j < 26; ++j) {
			counts[j][i] = counts[j][i - 1];
		}
		counts[S[i] - 'a'][i]++;
	}

	// 특정 알파벳의 등장 횟수 계산 후 출력
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