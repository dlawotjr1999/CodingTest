#include <iostream>
#include <vector>
#include <queue>

// 최대 유량 문제
// Admonds-Karp Algorithm 사용

constexpr int MAX = 52;
constexpr int INF = 1e9;

int capacity[MAX][MAX];
int flowPassed[MAX][MAX];
std::vector<int> vec[MAX];

int idx(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    return c - 'a' + 26;
}

// Adonds-Karp Algorithm
int edmondsKarp(int source, int sink) {
    int maxFlow = 0;

    while (true) {
        std::vector<int> parent(MAX, -1);
        std::queue<int> q;

        parent[source] = source;
        q.push(source);

        while (!q.empty() && parent[sink] == -1) {
            int u = q.front(); q.pop();
            for (int v : vec[u]) {
                if (parent[v] == -1 && capacity[u][v] - flowPassed[u][v] > 0) {
                    parent[v] = u;
                    q.push(v);
                    if (v == sink) break;
                }
            }
        }

        if (parent[sink] == -1) break;

        int flow = INF;
        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flow = std::min(flow, capacity[u][v] - flowPassed[u][v]);
        }

        for (int v = sink; v != source; v = parent[v]) {
            int u = parent[v];
            flowPassed[u][v] += flow;
            flowPassed[v][u] -= flow;
        }

        maxFlow += flow;
    }
    return maxFlow;
}


int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        char start, end;
        int c;

        std::cin >> start >> end >> c;

        int u = idx(start), v = idx(end);

        capacity[u][v] += c;
        capacity[v][u] += c;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }

    int source = idx('A');
    int sink = idx('Z');

    std::cout << edmondsKarp(source, sink) << "\n";
    return 0;
}
