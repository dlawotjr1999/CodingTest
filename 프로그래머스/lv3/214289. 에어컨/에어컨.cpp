#include <string>
#include <vector>

const int MAX = 1e8;

using namespace std;

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int n = onboard.size();
    int answer = MAX;
    
    t1 += 10; t2 += 10; temperature += 10;
    vector<vector<int>> DP(n, vector<int>(51, MAX));
    DP[0][temperature] = 0;
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j <= 50; j++) {
            if(onboard[i] == 1 && (j < t1 || j > t2))
                continue;
            
            DP[i + 1][j] = min(DP[i + 1][j], DP[i][j] + b);
            if(j >= 1) 
                DP[i + 1][j - 1] = min(DP[i + 1][j - 1], DP[i][j] + a);
            if(j < 50) 
                DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j] + a);
            
            if(temperature == j)
                DP[i + 1][j] = min(DP[i + 1][j], DP[i][j]);
            else if(temperature > j && j < 50)
                DP[i + 1][j + 1] = min(DP[i + 1][j + 1], DP[i][j]);
            else if(temperature < j && j >= 1)
                DP[i + 1][j - 1] = min(DP[i + 1][j - 1], DP[i][j]);
        }
    }
    
    for(int i = 0; i <= 50; ++i) {
        if(onboard[n - 1] == 1 && (i < t1 || i > t2))
            continue;
        answer = min(answer, DP[n - 1][i]);
    }
    
    return answer;
}