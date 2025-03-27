#include <iostream>
#include <string>

// 입력으로 주어진 수식에서 숫자를 묶어 최솟값을 만드는 문제
// idea : 처음 등장하는 - 뒤의 숫자부터 모두 결괏값에서 빼주면 최솟값이 나온다
int main() {
	std::string input;
	std::string temp = "";

	int result = 0;
	bool isMinus = false;

	std::cin >> input;

	// EOF까지 고려해야 하므로 반복문은 input.size()까지 반복한다
	for (int i = 0; i <= input.size(); i++) {
		if (input[i] == '+' || input[i] == '-' || input[i] == '\0') {
			if (isMinus)
				result -= stoi(temp);
			else
				result += stoi(temp);
			temp = "";
			// 처음 -가 나타나면, 그 뒤의 모든 숫자는 빼준다
			if (input[i] == '-') {
				isMinus = true;
			}
		}
		// 부호가 아닌 경우는 stoi로 계산할 수 있도록 temp에 삽입
		else
			temp += input[i];
	}

	std::cout << result;

	return 0;
}