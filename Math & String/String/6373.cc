#include <bits/stdc++.h>

// 1부터 n(n은 원래 숫자의 자릿수)까지 곱했을 때, 원래 숫자의 순환 형태가 나타나는 숫자를 순환수라 함
// 142857의 순환수는 285714, 428571 등이 있으며, 순서가 바뀌는 148257과 같은 경우는 순환이 아님
// 주어진 수가 순환수인지를 확인하는 문제

int main() {
	std::string input;

	while (std::cin >> input) {
		bool isCyclic = true;
		
		// 순환부를 쉽게 찾기 위해 2개의 input을 이어 붙임
		std::string doubled = input + input;

		// 1부터 n까지의 곱셈 결과를 확인
		for (int i = 1; i <= (int)input.length(); ++i) {
			std::string res = "";
			int carry = 0;
			int digit = 0;

			for (int j = (int)input.length() - 1; j >= 0; --j) {
				int cur = (input[j] - '0') * i + carry;
				carry = cur / 10; 
				digit = cur % 10;
				res += (digit + '0');
			}

			// 뒷자리부터 연산을 진행하기 때문에 연산 결과는 원하던 결과와 반대로 뒤집히게 되므로 reverse 진행
			std::reverse(res.begin(), res.end());

			// 첫째 자릿수와 i를 곱했을 때 carry가 존재하면 자릿수가 늘어나므로(n+1 자릿수가 됨) 순환수가 될 수 없음 
			if (carry > 0) {
				isCyclic = false;
				break;
			}

			// 연산 결과가 순환적이지 않으면 순환수가 될 수 없음
			if (doubled.find(res) == std::string::npos) {
				isCyclic = false;
				break;
			}
		}

		std::cout << (isCyclic ? (input + " is cyclic\n") : (input + " is not cyclic\n"));
	}

	return 0;
}