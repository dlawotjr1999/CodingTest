#include <string>
#include <vector>

using namespace std;

const long long MOD = 1000000007LL;

int solution(int n) {
    vector<long long> DP(n + 1, 0);
    if(n % 2 != 0)
        return 0;
    
    DP[0] = 1;
    DP[2] = 3;
    DP[4] = 11;
    for(int i = 6; i <= n; i += 2) {
        DP[i] = (DP[i - 2] * 3) % MOD;
        
        for(int j = i - 4; j >= 0; j -= 2) {
            DP[i] = (DP[i] + DP[j] * 2) % MOD; 
        }
    }
    
    return DP[n] % MOD;
}