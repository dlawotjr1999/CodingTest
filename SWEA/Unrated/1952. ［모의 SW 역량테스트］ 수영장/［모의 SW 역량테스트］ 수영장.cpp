#include <bits/stdc++.h>

using namespace std;

int costs[4];
int months[12];

void DFS(int& answer, int month, int cost) {
	if (cost >= answer)
		return;
	
	if (month >= 12) {
		answer = min(answer, cost);
		return;
	}

	DFS(answer, month + 1, cost + (costs[0] * months[month]));
	DFS(answer, month + 1, cost + costs[1]);
	DFS(answer, month + 3, cost + costs[2]);
}

int main() {
	int T;	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		for (int i = 0; i < 4; ++i) {
			cin >> costs[i];
		}

		for (int i = 0; i < 12; ++i) {
			cin >> months[i];
		}

		int answer = costs[3];
		DFS(answer, 0, 0);
		printf("#%d %d\n", tc, answer);

		memset(costs, 0, sizeof(costs));
		memset(months, 0, sizeof(months));
	}
	
	return 0;
}