#include <iostream>

typedef long long ll;

int N; ll X;

ll burger[51];
ll patty[51];

ll GetAnswer(int n, ll x) {
	if (x == 1)
		return 0;
	else if (x < burger[n - 1] + 1)
		return GetAnswer(n - 1, x - 1);
	else if (x == 1 + burger[n - 1])
		return patty[n - 1];
	else if (x == 1 + burger[n - 1] + 1)
		return patty[n - 1] + 1;
	else if (x < 1 + burger[n - 1] + 1 + burger[n - 1])
		return patty[n - 1] + 1 + GetAnswer(n - 1, x - 1 - burger[n - 1] - 1);
	else
		return patty[n];
}

int main() {
	std::cin >> N >> X;

	burger[0] = 1;
	patty[0] = 1;

	for (int i = 1; i <= N; ++i)
	{
		burger[i] = 1 + burger[i - 1] + 1 + burger[i - 1] + 1; 
		patty[i] = patty[i - 1] + 1 + patty[i - 1]; 
	}

	std::cout << GetAnswer(N, X);
	return 0;
}