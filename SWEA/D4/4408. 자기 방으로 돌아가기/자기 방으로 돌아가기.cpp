#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T; cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		vector<int> rooms(201, 0);
		
		int N; cin >> N;
		while (N--) {
			int s, e;
			cin >> s >> e;

			s = (s % 2 == 0 ? s - 1 : s);
			e = (e % 2 == 0 ? e - 1 : e);

			int start = (min(s, e) + 1) / 2;
			int end = (max(s, e) + 1) / 2;

			for (int i = start; i <= end; ++i) {
				rooms[i]++;
			}
		}

		printf("#%d %d\n", tc, *max_element(rooms.begin(), rooms.end()));
	}

	return 0;
}