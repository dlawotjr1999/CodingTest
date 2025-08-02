#include <iostream>
#include <algorithm>

// 그룹 단어란 단어에 존재하는 모든 문자에 대해서, 각 문자가 연속해서 나타나는 경우를 의미함
// 예를 들면, ccazzzzbb는 c, a, z, b가 모두 연속해서 나타나기 때문에 그룹 단어이지만, aabbbccb는 b가 떨어져서 나타나기 때문에 그룹 단어가 아님
// 이 때, 주어진 문자열들이 그룹 단어인지를 판별하는 문제

int cnt;

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		bool is_group = true;

		// 문자들의 등장 여부를 체크하기 위해 알파벳 배열 선언
		bool alphabet[26];
		std::fill_n(alphabet, 26, false);

		std::string input;
		std::cin >> input;

		alphabet[input[0] - 'a'] = true;
		for (int j = 1; j < input.size(); ++j) {

			// 판별하고자 하는 알파벳이 이미 체크되어 있음에도 앞뒤 문자가 다르면 그룹 단어가 아님
			// 즉, 이미 등장했던 알파벳이 다른 문자 그룹들의 뒤에 나타나면 그룹 문자가 될 수 없음
			if (alphabet[input[j] - 'a'] == true && input[j - 1] != input[j]) {
				is_group = false;
			}

			// 위의 경우를 제외한 경우에는 현재 알파벳에 체크
			alphabet[input[j] - 'a'] = true;
		}

		if (is_group)
			cnt++;
	}

	std::cout << cnt;
	return 0;
}