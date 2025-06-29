#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

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