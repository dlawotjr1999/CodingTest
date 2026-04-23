#include <string>
#include <vector>

using namespace std;

const int INF = 1e9;
vector<vector<int>> DP;

int mul(int l, int r, const vector<vector<int>>& matrix_sizes) {
    if(l == r)
        return 0;
    
    if(DP[l][r] != -1)
        return DP[l][r];
    
    DP[l][r] = INF;
    for(int k = l; k < r; ++k) {
        int cost = mul(l, k, matrix_sizes) + mul(k + 1, r, matrix_sizes)
            + matrix_sizes[l][0] * matrix_sizes[k][1] * matrix_sizes[r][1];
        DP[l][r] = min(DP[l][r], cost);
    }
    
    return DP[l][r]; 
}

int solution(vector<vector<int>> matrix_sizes) {
    int n = matrix_sizes.size();
    DP.assign(n, vector<int>(n, -1));
    
    return mul(0, n-1, matrix_sizes);
}