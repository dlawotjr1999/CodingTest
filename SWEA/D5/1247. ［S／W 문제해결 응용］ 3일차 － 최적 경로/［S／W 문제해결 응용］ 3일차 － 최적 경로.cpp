#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1e9;

int N;
vector<pair<int, int>> coords;
vector<vector<int>> DP;

int GetDist(int a, int b) {
	return abs(coords[a].first - coords[b].first)
		+ abs(coords[a].second - coords[b].second);
}

int DFS(int cur, int mask) {
	if (mask == (1 << N) - 1)
		return GetDist(cur, 1);

	int& ret = DP[cur][mask];

	if (ret != -1)
		return DP[cur][mask];

	ret = MAX;
	for (int i = 0; i < N; ++i) {
		if (mask & (1 << i))
			continue;
		int next = i + 2;

		ret = min(ret, GetDist(cur, next) + DFS(next, mask | (1 << i)));
	}

	return ret;
}

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		cin >> N;

		coords.clear();
		for (int i = 0; i < N + 2; ++i) {
			int y, x; cin >> y >> x;
			coords.emplace_back(y, x);
		}
		DP.assign(N + 2, vector<int>(1 << N, -1));

		int answer = DFS(0, 0);
		cout << "#" << tc << " " << answer << '\n';
	}

	return 0;
}