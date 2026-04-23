#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<vector<int>> DP;

void DFS(int s = 1) {
    visited[s] = true;
    DP[s][0] = 0;
    DP[s][1] = 1;
    
    for(int next : graph[s]) {
        if(visited[next])
            continue;
        DFS(next);
        
        DP[s][0] += DP[next][1];
        DP[s][1] += min(DP[next][0], DP[next][1]);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    graph.assign(n + 1, {});
    visited.assign(n + 1, false);
    DP.assign(n + 1, vector<int>(2, 0));
    
    for(vector<int> edge : lighthouse) {
        int s = edge[0], e = edge[1];
        
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    DFS();
    
    return min(DP[1][0], DP[1][1]);
}