#include <iostream>

// 레벨-L 버거가 다음과 같이 이루어져 있다고 하자
// 1. 레벨-0 버거는 패티만으로 이루어져 있음
// 2. 레벨-L 버거는 햄버거번, 레벨 - (L-1) 버거, 패티, 레벨 - (L-1)버거, 햄버거번으로 이루어져 있음
// 이 때, 레벨-L 버거의 아래 X장을 먹었을 때, 먹은 패티의 수를 구하는 문제

typedef long long ll;

int N; ll X;

ll burger[51];	// 레벨-N 버거의 크기 저장
ll patty[51];	// 레벨-N 버거의 패티의 수 저장

// 분할-정복으로 burger, patty 배열을 활용하여 먹은 패티의 수를 구함 
ll GetAnswer(int n, ll x) {
	// 레벨-0 버거일 경우 : 먹을 경우에는 1, 먹지 않을 경우에는 0 
	if (n == 0) {
		if (x == 0)
			return 0;
		else if (x == 1)
			return 1;
	}
	
	// 가장 아래는 무조건 햄버거 번
	if (x == 1)
		return 0;
	// 레벨-n 버거를 (번 + (n-1) 버거)보다 적게 먹었을 경우 : 맨 위 번을 제외한 레벨-(n-1) 버거 내부 일부
	else if (x < 1 + burger[n - 1])
		return GetAnswer(n - 1, x - 1);
	// 레벨-n 버거를 (번 + (n-1) 버거)만큼 먹었을 경우 : patty[n - 1]
	else if (x == 1 + burger[n - 1])
		return patty[n - 1];
	// 레벨-n 버거를 (번 + (n-1) 버거 + 패티)만큼 먹었을 경우 : patty[n] + 1
	else if (x == 1 + burger[n - 1] + 1)
		return patty[n - 1] + 1;
	// 레벨-n 버거를 (번 + (n-1) 버거 + 패티 (n-1) 버거)보다 적게 먹었을 경우 : patty[n - 1] + 중앙 패티 이후 위쪽의 레벨-(n-1) 버거 내부 일부
	else if (x < 1 + burger[n - 1] + 1 + burger[n - 1])
		return patty[n - 1] + 1 + GetAnswer(n - 1, x - (1 + burger[n - 1] + 1));
	// 레벨-n 버거를 다 먹었을 경우 : patty[n]
	else
		return patty[n];
}

int main() 
	std::cin >> N >> X;

	burger[0] = 1;
	patty[0] = 1;

	// 1부터 N까지 버거의 크기 배열과 패티의 수 배열을 계산
	for (int i = 1; i <= N; ++i)
	{
		burger[i] = 1 + burger[i - 1] + 1 + burger[i - 1] + 1; 
		patty[i] = patty[i - 1] + 1 + patty[i - 1]; 
	}

	std::cout << GetAnswer(N, X);
	return 0;
}