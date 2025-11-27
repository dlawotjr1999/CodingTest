#include <iostream>

const int INF = 1e9;
int dist[401][401];

int answer = INF;

int main() {
    int V, E;
    std::cin >> V >> E;

    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            dist[i][j] = INF;
        }
    }

    for (int i = 0; i < E; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        dist[a][b] = std::min(dist[a][b], c);
    }

    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 1; i <= V; i++)
        answer = std::min(answer, dist[i][i]);

    std::cout << (answer == INF ? -1 : answer);
    return 0;
}