#include <bits/stdc++.h>

// 의 갯수와 1의 갯수가 각각 짝수 개인 문자열 S가 존재함
// 이 때 S를 구성하는 문자 중 절반의 0과 1이 제거된 새로운 문자열 S'을 만들고자 함
// S'로 가능한 문자열 중 사전 순으로 가장 빠른 것을 구하는 문제

// S'은 절반의 0과 1을 제거함으로써 만들어질 수 있는 문자열. 즉 단순히 절반의 갯수로만 이루어졌다고 S'에 해당하지 않음
// S에서 1은 앞에서부터, 0은 뒤에서부터 제거해야 사전 순으로 가장 빠른 S'을 구할 수 있음

int main() {
	std::string S;
	std::cin >> S;

	int zero_cnt = 0, one_cnt = 0;

	for (int i = 0; i < S.length(); ++i) {
		if (S[i] == '0')
			zero_cnt++;
		else
			one_cnt++;
	}

	// 입력된 문자열에서 0과 1의 갯수를 각각 절반으로 나눔
	zero_cnt /= 2, one_cnt /= 2;
	int zero_idx = 0, one_idx = 0;

	// 1부터 제거. S를 앞에서부터 탐색하며 one_cnt만큼의 1을 제거함
	std::string temp = "";
	for (char c : S) {
		if (c == '1' && one_idx < one_cnt) {
			one_idx++;
		}
		else
			temp.push_back(c);
	}
	
	// 현재 temp 문자열은 S에서 0은 그대로 남으며, 1은 절반이 제거된 상태의 문자열임
	// 0 제거. temp의 뒤에서부터 탐색하며, zero_cnt만큼의 0을 제거함
	std::string answer = "";
	for (int i = temp.length() - 1; i >= 0; --i) {
		char c = temp[i];
		if (c == '0' && zero_idx < zero_cnt) {
			zero_idx++;
		}
		else
			answer.push_back(c);
	}

	// 현재 answer 문자열은 push_back 연산으로 인하여 one_cnt개의 1이 앞에, zero_cnt개의 0이 뒤에 있는 상태. 즉 사전 순에서 가장 뒤에 있는 문자열
	// 문자열을 뒤집으면 최종적으로 사전 순에서 가장 빠른 문자열이 만들어짐
	std::reverse(answer.begin(), answer.end());

	std::cout << answer;
	return 0;
}