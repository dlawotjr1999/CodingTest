#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; ++tc) {
        int N;
        cin >> N;

        vector<int> vec(N);
        int total = 0;
        for (int i = 0; i < N; ++i) {
            cin >> vec[i];
            total += vec[i];
        }

        vector<bool> dp(total + 1, false);
        dp[0] = true;

        for (int x : vec) {
            for (int s = total - x; s >= 0; --s) {
                if (dp[s]) {
                    dp[s + x] = true;
                }
            }
        }

        int answer = 0;
        for (bool possible : dp) {
            if (possible) answer++;
        }

        cout << "#" << tc << " " << answer << "\n";
    }

    return 0;
}