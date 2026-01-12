#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;	cin >> T;

	for (int tc = 1; tc <= T; ++tc) {
		int N;	cin >> N;

		vector<vector<int>> field(N, vector<int>(N));
		
		int s_row = 0, s_col = 0;
		int cur = 1;

		int size = N;
		while (size > 0) {
			for (int i = 0; i < size; ++i) {
				field[s_row][s_col + i] = cur;
				cur++;
			}

			for (int i = 1; i < size; ++i) {
				field[s_row + i][s_col + size - 1] = cur;
				cur++;
			}

			for (int i = size - 2; i >= 0; --i) {
				field[s_row + size - 1][s_col + i] = cur;
				cur++;
			}

			for (int i = size - 2; i >= 1; --i) {
				field[s_row + i][s_col] = cur;
				cur++;
			}

			size -= 2;
			s_row++; s_col++;
		}

		cout << '#' << tc << '\n';
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << field[i][j] << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}