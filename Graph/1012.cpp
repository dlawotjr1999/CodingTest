#include <iostream>
#include <cstring> 

int M, N, K;
int graph[51][51];
int visited[51][51];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void DFS(int x, int y) {
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || nx >= M || ny < 0 || ny >= N)
            continue;
        if (graph[ny][nx] == 1 && !visited[ny][nx])
            DFS(nx, ny);
    }
}

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        std::cin >> M >> N >> K;

        memset(graph, 0, sizeof(graph));
        memset(visited, 0, sizeof(visited));

        for (int i = 0; i < K; i++) {
            int m, n;
            std::cin >> m >> n;
            graph[n][m] = 1;
        }

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (graph[i][j] == 1 && !visited[i][j]) {
                    DFS(j, i);
                    cnt++;
                }
            }
        }

        std::cout << cnt << std::endl;
    }
    return 0;
}
