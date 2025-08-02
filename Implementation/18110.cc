#include <bits/stdc++.h>

// solved.ac의 난이도 결정 방식을 구하는 문제
// 난이도 결정 방식은 아래와 같이 결정됨
// 1. 아직 아무 의견이 없다면 문제의 난이도는 0으로 결정
// 2. 의견이 하나 이상 있다면, 문제의 난이도는 모든 사람의 난이도 의견의 30 % 절사평균으로 결정(즉 상위, 하위 15프로는 배제함)

int main() {
	int n;
	std::cin >> n;

	if (n == 0) {
		std::cout << 0;
		return 0;
	}

	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> vec[i];
	}

	std::sort(vec.begin(), vec.end());
	// 정확도를 위해 0.15를 곱하기 보다는 (n * 3) / 20을 채택
	int except = round(double(n * 3) / 20);

	// 30프로 절사평균 계산
	double sum = 0;
	for (int i = except; i < n - except; ++i) {
		sum += vec[i];
	}

	double avg = round(sum / (n - 2 * except));

	// 계산 결과는 정수로 반올림
	std::cout << std::fixed << std::setprecision(0) << avg;
	return 0;
}