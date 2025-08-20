#include <iostream>
#include <string>

// 공백없이 쓰여진 1부터 N까지의 수들로 이루어진 문자열이 있음
// 위 문자열에서 일부가 지워졌을 때, 지워진 문자열로부터 유추 가능한 N의 최솟값을 구하는 문제

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::string str;
	std::cin >> str;
	
	int N = 1;
	int idx = 0;

	while (true) {
		// N을 일단 문자열로 치환(비교를 용이하게 하기 위함)
		std::string temp = std::to_string(N);

		// 자릿수를 비교해 나가며 idx == N인 경우에 다음 문자로 이동
		// N이 한 자릿 수가 아닌 경우에는 각 자릿수를 비교해 가면서 다음 문자로 이동
		for (int i = 0; i < temp.length(); ++i) {
			if (str[idx] == temp[i])
				idx++;
			if (idx >= str.length()) {
				std::cout << N;
				return 0;
			}
		}
		N++;
	}
	return 0;
}