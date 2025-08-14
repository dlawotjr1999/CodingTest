#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

// MooTube는 N개의 동영상을 노드로, N−1개의 USADO를 간선으로 한 그래프로 표현됨
// 두 동영상 간 USADO는 경로 상 모든 간선의 USADO 중 최솟값으로 정의됨
// 이 때, 각 질의 (K, v)는 동영상 v에서 USADO >= K인 모든 동영상의 갯수를 의미함
// 각 질의들에 대해서 (K, v)의 값들을 구하는 문제

constexpr int MAX = 5000;

int N, Q;
std::vector<std::pair<int, int>> field[MAX + 1];
bool visited[MAX + 1];

int BFS(int start, int k) {
    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    int cnt = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // 두 동영상 간 USADO는 경로 상 모든 간선의 USADO 중 최솟값으로 정의됨  
        // 따라서 현재 간선 cost >= k 일 때만 v를 방문해야 경로 전체의 최소 USADO >= k 가 보장됨
        for (auto [v, cost] : field[u]) {
            if (!visited[v] && cost >= k) {
                visited[v] = true;
                cnt++;
                q.push(v);
            }
        }
    }
    return cnt;
}

int main() {
    std::cin >> N >> Q;

    // 인접 리스트 방식으로 그래프 생성
    for (int i = 0; i < N - 1; ++i) {
        int p, q, r;
        std::cin >> p >> q >> r;
        field[p].push_back({ q, r });
        field[q].push_back({ p, r });
    }

    while (Q--) {
        int k, v;
        std::cin >> k >> v;
        
        memset(visited, false, sizeof(visited));
        std::cout << BFS(v, k) << '\n';
    }

    return 0;
}