#include <bits/stdc++.h>

// 어떤 리조트의 이용권은 아래와 같이 세 종류로 이루어져 있으며, 쿠폰 세 장은 하루 이용권으로 교환할 수 있음
// - 하루 이용권(10,000원), 쿠폰 없음
// - 연속 3일권(25,000원), 쿠폰 1장
// - 연속 5일권(37,000원), 쿠폰 2장
// N일의 여름방학 중 리조트를 갈 수 없는 M일이 있으며, 그 외의 모든 날은 리조트에서 보내고자 함
// 여름방학 기간과 리조트에 갈 수 없는 날의 정보가 주어질 때, 리조트를 이용하기 위해서 지불해야 하는 최소비용을 구하는 문제

const int INF = 1e9;
int N, M;

// DP[i][j] : j개의 쿠폰이 존재할때, i일부터 N일까지의 최소 리조트 이용 비용
int DP[101][41];
bool holiday[101];

// Top-Down 방식으로 DP 배열을 채움
int DFS(int day, int coupon) {
	// 여름방학 일수를 넘기면 종료
	if (day > N)
		return 0;
	// 테이블에 이미 값이 채워져 있으면 그 값을 반환
	if (DP[day][coupon] != INF)
		return DP[day][coupon];
	// 현재 날짜가 주말이면 그대로 다음날 값으로 전이
	if (holiday[day]) 
		return DP[day][coupon] = DFS(day + 1, coupon);

	// 조건에 맞게 테이블에 값을 채움
	DP[day][coupon] = std::min(DP[day][coupon], DFS(day + 1, coupon) + 10000);
	DP[day][coupon] = std::min(DP[day][coupon], DFS(day + 3, coupon + 1) + 25000);
	DP[day][coupon] = std::min(DP[day][coupon], DFS(day + 5, coupon + 2) + 37000);

	// 쿠폰이 세 장 이상일 때 쿠폰을 사용한 경우
	// 다음 날짜로 전이 및 쿠폰 갯수 감소
	if (coupon >= 3)
		DP[day][coupon] = std::min(DP[day][coupon], DFS(day + 1, coupon - 3));
	
	return DP[day][coupon];
}

int main() {
	std::cin >> N >> M;

	// 리조트에 갈 수 없는 날을 저장
	for (int i = 0; i < M; i++) {
		int d; std::cin >> d;
		holiday[d] = true;
	}

	// INF 값으로 초기화
	for (int i = 1; i <= N; i++)
		for (int j = 0; j <= 40; j++)
			DP[i][j] = INF;
	
	// 초기 상태(1, 0)에서 N일까지의 최소 이용 비용을 구해야 함
	int answer = DFS(1, 0);

	std::cout << answer;
	return 0;
}