#include <string>
#include <vector>
#include <queue>

using namespace std;

int max_depth;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> depth_vec;

void BFS(int cur) {
    queue<pair<int, int>> q;
    
    visited[cur] = true;
    q.emplace(cur, 0);
    depth_vec[cur] = 0;
    
    while(!q.empty()) {
        auto [cur, dist] = q.front();
        max_depth = max(max_depth, dist);
        q.pop();
        
        for(auto next : graph[cur]) {
            if(!visited[next]) {
                visited[next] = true;
                q.emplace(next, dist + 1);
                depth_vec[next] = dist + 1;
            }   
        }
    }
}

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    max_depth = 0;
    graph.assign(n + 1, {});
    visited.assign(n + 1, false);
    depth_vec.assign(n + 1, 0);
    
    for(auto& e : edge) {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
    }
    
    BFS(1);
    for(int i = 1; i <= n; ++i) {
        if(depth_vec[i] == max_depth)
            answer++;
    }
    
    return answer;
}