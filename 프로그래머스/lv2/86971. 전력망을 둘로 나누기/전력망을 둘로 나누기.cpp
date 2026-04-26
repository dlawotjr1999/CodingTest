#include <string>
#include <vector>

using namespace std;

vector<int> graph[101];
vector<bool> visited(101);

int DFS(int s) {
    int cnt = 1;
    visited[s] = true;
    
    for(int next : graph[s]) {
        if(!visited[next])
            cnt += DFS(next);
    }
    
    return cnt; 
}

int solution(int n, vector<vector<int>> wires) {
    int answer = 100;
    int cur = n - 2;
    
    while(cur >= 0) {
        for(int i = 0; i < (int)wires.size(); ++i) {
            if(i == cur)
                continue;
            graph[wires[i][0]].push_back(wires[i][1]);
            graph[wires[i][1]].push_back(wires[i][0]);
        }
        
        int v1 = DFS(1);
        int v2 = n - v1;
        answer = min(answer, abs(v1 - v2));
        
        for(int j = 1; j <= 100; ++j)
            graph[j].clear();
        fill(visited.begin(), visited.end(), false);
        cur--;
    }
    
    return answer;
}