#include <bits/stdc++.h>

// 빨간색 공과 파란색 공이 일직선상에 섞여 놓여 있으며, 공을 옮겨서 같은 색 공끼리 인접하게 놓이도록 하고자 함
// 공을 옮길 때는 아래 두 가지의 규칙이 적용됨
// - 바로 옆에 다른 색깔의 볼이 있으면 그 볼을 모두 뛰어 넘어 옮길 수 있음
// - 옮길 수 있는 볼의 색깔은 한 가지 즉, 빨간색 공을 처음에 옮겼으면 다음에도 빨간색 공만 옮길 수 있음
// 공에 관한 정보가 주어질 때, 규칙에 따라 공을 이동하여 같은 색끼리 모으되 최소 이동횟수를 구하는 문제

int equal_left, diff_left;
int equal_right, diff_right;

int main() {
	int N;	std::cin >> N;

	std::string str = "";
	for (int i = 0; i < N; ++i) {
		char c;	std::cin >> c;
		str += c;
	}

	// 공을 왼쪽으로 모을 경우에는 가장 왼쪽의 공의 색을 기준으로 삼음
	char base = str[0];
	bool isChanged = false;

	// 기준 공과 같은 색의 공을 왼쪽으로 모는 경우
	// 왼쪽 끝에 연속으로 붙어 있던 기준 공 덩어리가 끊긴 이후, 다시 등장하는 기준 공의 개수를 셈
	// 위 조건에 해당하는 공들만 실제로 이동이 필요하기 때문 
	for (int i = 0; i < N; ++i) {
		if (str[i] != base)
			isChanged = true;
		else if (isChanged && str[i] == base)
			equal_left++;
	}

	// 기준 공과 다른 색의 공을 왼쪽으로 모는 경우의 수는 다른 색 공들의 갯수와 동일함
	for (int i = 0; i < N; ++i) {
		if (str[i] != base)
			diff_left++;
	}

	// 공을 오른쪽으로 모을 경우에는 가장 오른쪽의 공의 색을 기준으로 삼음
	base = str[N - 1];
	isChanged = false;

	// 기준 공과 같은 색의 공을 오른쪽으로 모는 경우
	// 왼쪽으로 모는 방식과 동일하지만 역순으로 진행
	for (int i = N - 1; i >= 0; --i) {
		if (str[i] != base)
			isChanged = true;
		else if (isChanged && str[i] == base)
			equal_right++;
	}

	// 기준 공과 다른 색의 공을 오른쪽으로 모는 경우의 수 역시 다른 색 공들의 갯수와 동일함
	for (int i = N - 1; i >= 0; --i) {
		if (str[i] != base)
			diff_right++;
	}

	// 위 네 가지의 경우의 수들 중 가장 작은 값이 정답
	std::cout << std::min({equal_left, diff_left, equal_right, diff_right});
	return 0;
}