#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> DP;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    DP.resize(n, vector<int>(m, 0));
    
    for(vector<int> p : puddles) {
        DP[p[1] - 1][p[0] - 1] = -1;
    }
    
    for(int r = 0; r < n ; ++r) {
        if(DP[r][0] == -1)
            break;
        DP[r][0] = 1;
    }
    
    for(int c = 0; c < m; ++c) {
        if(DP[0][c] == -1)
            break;
        DP[0][c] = 1;
    }
    
    for(int r = 1; r < n; ++r) {
        for(int c = 1; c < m; ++c) {
            if(DP[r][c] == -1)
                continue;
            
            if(DP[r - 1][c] == -1 && DP[r][c - 1] == -1)
                DP[r][c] = 0;
            else if(DP[r - 1][c] == -1) 
                DP[r][c] = DP[r][c - 1];
            else if(DP[r][c - 1] == -1) 
                DP[r][c] = DP[r - 1][c];
            else
                DP[r][c] = (DP[r - 1][c] + DP[r][c - 1]) % 1000000007;
        }
    }
    
    /*
    for(int r = 0; r < n; ++r) {
        for(int c = 0; c < m; ++c) 
            cout << DP[r][c];
         cout << '\n';
    }
    */
    
    answer = DP[n - 1][m - 1];
    return answer;
}