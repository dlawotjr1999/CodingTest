#include <bits/stdc++.h>

// 문자열 S에 0개 이상의 문자를 문자열 뒤에 추가해서 팰린드롬을 만들고자 함
// 이 때, S를 이용하여 만들 수 있는 가장 짧은 팰린드롬의 길이를 구하는 문제

int answer;

int main() {
	std::string str;
	std::cin >> str;

	// 문자열의 길이 n에 대해 구간 [i, n-1]의 문자열이 팰린드롬을 이룬다면
	// 문자열의 맨 뒤에 구간 [0, i-1]의 문자열을 덧붙이면 전체 문자열이 팰린드롬이 됨 
	for (int i = 0; i < str.length(); ++i) {
		bool isOk = true;
		int l = i, r = str.length() - 1;

		// 구간 [i, n-1]의 문자열이 팰린드롬인지 확인(양 끝에서부터 서로 가까워지는 방식으로 확인) 
		// l == r인 경우, 즉 하나의 문자 역시 팰린드롬이기 때문에 반복문의 조건을 l < r로 설정
		while (l < r) {
			if (str[l] != str[r]) {
				isOk = false;
				break;
			}
			l++;
			r--;
		}

		// 구간 [i, n-1]이 팰린드롬이라면 (현재 문자열의 길이 + 구간 [0, i-1]의 문자열의 길이, 즉 i)가 만들 수 있는 팰린드롬의 최소 길이
		if (isOk) {
			std::cout << str.length() + i;
			return 0;
		}
	}
}