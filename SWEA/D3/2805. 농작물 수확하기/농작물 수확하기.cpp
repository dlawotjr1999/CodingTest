#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 49;

int field[MAX][MAX];

int main() {
	int T; cin >> T;

	for (int t = 1; t <= T; ++t) {
		int N; cin >> N;
		int sum = 0;

		for (int i = 0; i < N; ++i) {
			string str; cin >> str;

			for (int j = 0; j < str.length(); ++j) {
				field[i][j] = str[j] - '0';
			}
		}

		int mid = N / 2;	
		int l = mid, r = mid;

		for (int i = 0; i <= mid; ++i) {
			for (int j = l; j <= r; ++j) {
				sum += field[i][j];
			}
			l--; r++;
		}
		l += 2; r -= 2;
		
		for (int i = mid + 1; i < N; ++i) {
			for (int j = l; j <= r; ++j) {
				sum += field[i][j];
			}
			l++; r--;
		}

		printf("#%d %d\n", t, sum);
		memset(field, 0, sizeof(field));
	}

}