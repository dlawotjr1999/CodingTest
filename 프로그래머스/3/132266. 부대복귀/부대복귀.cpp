#include <string>
#include <vector>
#include <queue>

using namespace std;

int N;

vector<vector<int>> graph;
vector<bool> visited;

int BFS(int s, int e) {
    queue<pair<int, int>> q;
    visited.assign(N + 1, false);
    
    q.emplace(s, 0);
    visited[s] = true;
    
    while(!q.empty()) {
        auto [cur_pos, cur_dist] = q.front();
        q.pop();
        
        if(cur_pos == e)
            return cur_dist;
        
        for(int next : graph[cur_pos]) {
            if(visited[next])
                continue;
            visited[next] = true;
            q.emplace(next, cur_dist + 1);
        }
    }
    
    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    graph.resize(n + 1, {});
    visited.resize(n + 1, false);
    N = n;
    
    for(vector<int> road : roads) {
        int s = road[0], r = road[1];
        graph[s].push_back(r);
        graph[r].push_back(s);
    }
    
    for(int s : sources) {
        int dist = BFS(s, destination);
        answer.push_back(dist);
    }
    
    return answer;
}