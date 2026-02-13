#include <bits/stdc++.h>

const int INF = 1e9;
int N, M;

int DP[101][40];
bool holiday[101];

int DFS(int day, int coupon) {
	if (day > N)
		return 0;
	if (DP[day][coupon] != INF)
		return DP[day][coupon];
	if (holiday[day]) 
		return DP[day][coupon] = DFS(day + 1, coupon);

	DP[day][coupon] = std::min(DP[day][coupon], DFS(day + 1, coupon) + 10000);
	DP[day][coupon] = std::min(DP[day][coupon], DFS(day + 3, coupon + 1) + 25000);
	DP[day][coupon] = std::min(DP[day][coupon], DFS(day + 5, coupon + 2) + 37000);

	if (coupon >= 3)
		DP[day][coupon] = std::min(DP[day][coupon], DFS(day + 1, coupon - 3));
	
	return DP[day][coupon];
}

int main() {
	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int d; std::cin >> d;
		holiday[d] = true;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 40; j++)
			DP[i][j] = INF;
	
	int answer = DFS(1, 0);

	std::cout << answer;
	return 0;
}