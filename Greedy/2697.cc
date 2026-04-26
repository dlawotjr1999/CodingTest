#include <bits/stdc++.h>

int main() {
	int T; std::cin >> T;

	while (T--) {
		std::string str; std::cin >> str;
		
		bool isBiggest = false;
		std::string answer = str;

		// 값을 내려가면서 확인해야 하기 때문에 현재 조합으로 만들 수 있는 가장 큰 수를 임시 답으로 설정 
		std::sort(answer.begin(), answer.end(), std::greater<char>());

		// 각 자릿수를 탐색하면서 현재 자릿수보다 큰 값을 가지는 뒤의 자릿수를 찾음
		// 원래 수의 다음수는 원래수보다 크기 때문 
		for (int i = 0; i < str.length(); ++i) {
			for (int j = i + 1; j < str.length(); ++j) {
				if (str[i] < str[j]) {
					std::string temp = str;

					// 두 값을 교환 후 기준 위치(i) 뒤의 수들은 모두 오름차순으로 정렬
					// 매 반복을 통해 그 중 가장 작은 수가 다음수가 됨
					std::swap(temp[i], temp[j]);
					std::sort(temp.begin() + i + 1, temp.end());
					if (str < temp)
						answer = std::min(temp, answer);
				}
			}
		}

		// 입력된 수가 가장 큰 수인 경우에는 BIGGEST 출력
		if (str == answer)
			isBiggest = true;

		std::cout << (!isBiggest ? answer : "BIGGEST") << '\n';
	}

	return 0;
}