#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph, rgraph;
vector<bool> visited;

int DFS(int cur, const vector<vector<int>>& g) {
    visited[cur] = true;
    int cnt = 1;

    for (int next : g[cur]) {
        if (!visited[next]) {
            cnt += DFS(next, g);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    graph.assign(n + 1, {});
    rgraph.assign(n + 1, {});

    for (auto& r : results) {
        int win = r[0];
        int lose = r[1];
        graph[win].push_back(lose);
        rgraph[lose].push_back(win);
    }

    for (int i = 1; i <= n; ++i) {
        visited.assign(n + 1, false);
        int winCnt = DFS(i, graph) - 1;

        visited.assign(n + 1, false);
        int loseCnt = DFS(i, rgraph) - 1;
        
        if (winCnt + loseCnt == n - 1)
            answer++;
    }

    return answer;
}