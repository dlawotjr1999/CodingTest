#include <bits/stdc++.h>

// 자연수 A를 B번 곱한 수를 C로 나눈 나머지를 구하는 문제

long long A, B, C;

// 분할 정복 진행
long long Func(long long b) {
	if (b == 1)
		return A % C;

	// 지수 b가 짝수 : A^(b/2) * A^(b/2)로 분할
	// 지수 b가 홀수 : A^(b/2) * A^(b/2) * A로 분할 
	// 또한, (a * b) % m = ((a % m) * (b % m)) % m
	// 동일한 Func(b/2)를 두 번 호출하면 중복 계산이 발생하므로, 한 번만 계산하여 재사용함
	long long f = Func(b / 2) % C;
	if (b % 2 == 0) {
		return f * f % C;
	}
	else {
		return (f * f % C) * (A % C) % C;
	}
 }

int main() {
	std::cin >> A >> B >> C;
	
	std::cout << Func(B);
	return 0;
}