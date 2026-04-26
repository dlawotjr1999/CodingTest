#include <vector>

const int INF = 1e8;

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log) {
    int answer = 0;    
    vector<vector<int>> graph(n + 1);

    for (auto &e : edge_list) {
        int a = e[0], b = e[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i) {
        graph[i].push_back(i);
    }
    
    vector<vector<int>> DP(k, vector<int>(n + 1, INF));
    DP[0][gps_log[0]] = 0;
    
    for(int t = 1; t < k; ++t) {
        for(int cur = 1; cur <= n; ++cur) {
            for(int prev : graph[cur]) {
                if(DP[t - 1][prev] == INF)
                    continue;
                
                int cost = DP[t - 1][prev];
                if(cur != gps_log[t])
                    cost++;
                DP[t][cur] = min(DP[t][cur], cost);
            }  
        }
    }
    
    answer = DP[k - 1][gps_log[k - 1]];
    return (answer != INF ? answer : -1);
}