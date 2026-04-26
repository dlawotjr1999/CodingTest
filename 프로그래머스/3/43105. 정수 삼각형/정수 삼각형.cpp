#include <string>
#include <vector>

using namespace std;

/*
00
10 11
20 21 22
30 31 32 33
40 41 42 43 44
*/

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    int answer = 0;

    vector<vector<int>> DP(n + 1, vector<int>(n + 1, 0));
    DP[0][0] = triangle[0][0];
    
    for(int i = 1; i < n; ++i) {
        DP[i][0] = triangle[i][0] + DP[i - 1][0];
        DP[i][i] = triangle[i][i] + DP[i - 1][i - 1];
        
        for(int j = 1; j < i; ++j) {
            DP[i][j] = triangle[i][j] + max(DP[i - 1][j - 1], DP[i - 1][j]);
        }
    }
    
    for(int i = 0; i <= n; ++i) {
        answer = max(answer, DP[n - 1][i]);
    }
    return answer;
}