#include <bits/stdc++.h>

long long A, B, C;

long long Func(long long b) {
	if (b == 1)
		return A % C;

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