#include <bits/stdc++.h>

// 여러 에너지 드링크들을 한 데 모아 합치려고 함
// 한 음료수에 다른 음료수를 부을 때 절반은 흘리게 됨
// 즉, a의 양을 xa + (xb / 2)로 만들고 b를 버리거나, b의 양을 xb + (xa / 2)로 만들고 a를 버리는 두 경우가 존재함
// 위 조건을 고려하여 여러 에너지 드링크를 합쳐서 그 양의 최댓값을 구하는 문제

double answer;

int main() {
	int N;
	std::cin >> N;

	std::vector<double> beverages(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> beverages[i];
	}
	
	// 흘리는 양을 최소화해야 총 에너지 드링크의 양이 최댓값이 됨
	// 즉, 가장 들이가 큰 음료수를 제외한 나머지 음료수들을 들이가 큰 음료수에 부어서 합쳐야 함 
	std::sort(beverages.begin(), beverages.end());
	answer = beverages[N - 1];

	for (int i = 0; i < N - 1; ++i) {
		beverages[i] /= 2;
		answer += beverages[i];
	}

	// 10e-5까지 오차 허용
	answer = round(answer * 10e5) / 10e5;
	std::cout << answer;
}