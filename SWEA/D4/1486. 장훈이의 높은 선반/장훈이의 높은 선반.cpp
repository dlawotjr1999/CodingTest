#include <bits/stdc++.h>

using namespace std; 

int answer;

void DFS(const vector<int>& heights, int cur, int sum, int target) {
	if (sum >= target) {
		answer = min(answer, sum);
		return;
	}
	
	if (cur == heights.size())
		return;
	
	DFS(heights, cur + 1, sum + heights[cur], target);
	DFS(heights, cur + 1, sum, target);
}

int main() {
	int T;	cin >> T;

	for(int tc = 1; tc <= T; ++tc) {
		int N, B;
		cin >> N >> B;

		vector<int> heights(N);
		for (int i = 0; i < N; ++i) {
			cin >> heights[i];
		}

		answer = 1e6;
		DFS(heights, 0, 0, B);

		printf("#%d %d\n", tc, (answer - B));
	}

	return 0;
}