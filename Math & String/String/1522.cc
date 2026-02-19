#include <bits/stdc++.h>

// a와 b로만 이루어진 원형의 문자열이 주어질 때, a를 모두 연속으로 만들기 위해서 필요한 최소 교환 횟수를 구하는 문제

// 주어진 문자열에서 a를 모두 연속으로 만든다는 것은, 문자열에 속한 a의 갯수만큼 a가 연속적일 수 있음을 의미함
// 즉, a의 갯수만큼 구간을 만들고, 그 구간 내에 있는 b를 구간 밖의 a와 교환한 횟수를 구하면 됨

int answer;

int main() {
	std::string input; 
	std::cin >> input;

	int len = 0;
	int cnt = 0;

	// 주어진 문자열에서 a의 갯수를 셈
	for (int i = 0; i < input.length(); ++i) {
		if (input[i] == 'a') len++;
	}

	// window 초기화; 구간 내에서 b의 갯수를 셈
	for (int i = 0; i < len; ++i) {
		if (input[i] == 'b') cnt++;
	}
	
	answer = cnt;

	// 한 칸씩 나아가며 현재 구간 내에서 b의 갯수 갱신
	// 모든 구간에 대해서 가장 작은 b의 갯수를 가지는 경우가 정답
	for (int i = len; i < len + input.length(); ++i) {
		if (input[i % input.length()] == 'b') cnt++;
		if (input[(i - len) % input.length()] == 'b') cnt--;
		answer = std::min(answer, cnt);
	}

	std::cout << answer;
	return 0;
}