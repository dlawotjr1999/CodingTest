#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<long long> DP(n + 1, 0);
    DP[0] = 1;
    
    for(int coin : money) {
        for(int j = coin; j <= n; ++j) {
            DP[j] = (DP[j] + DP[j - coin]) % 1000000007;
        }
    }
    
    return DP[n];
}