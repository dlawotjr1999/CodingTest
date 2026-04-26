#include <string>
#include <vector>

using namespace std;

/*
1 : 1, 1+2, 1+2+3, 1+2+3+4, 1+2+3+4+5, ...
2 : 2, 2+3, 2+3+4, 2+3+4+5, 2+3+4+5+6, ...
3 : 3, 3+4, 3+4+5, 3+4+5+6, 3+4+5+6+7, ...
4 : 4, 4+5, 4+5+6, 4+5+6+7, 4+5+6+7+8, ...
.
.
.
*/
int solution(int n) {
    vector<int> DP(n + 1, 0);
    
    for(int i = 1; i <= n; ++i) {
        int cur = i;
        
        for(int j = i + 1; cur <= n; ++j) {
            DP[cur]++;
            cur += j;
        }
    }
        
    return DP[n];
}