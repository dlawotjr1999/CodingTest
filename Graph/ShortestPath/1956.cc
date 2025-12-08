#include <iostream>

// V개의 마을과 E개의 도로로 구성된 도시가 있으며, 각 도로는 일방 통행 도로임
// 도로를 따라 운동을 하기 위한 경로를 찾을 때, 다시 시작점으로 돌아오기 위하여 사이클을 찾고자 함
// 이 때, 도로의 길이의 합이 가장 작은 사이클을 구하는 문제

const int INF = 1e9;
int dist[401][401];

int answer = INF;

int main() {
    int V, E;
    std::cin >> V >> E;

    // 초기엔 경로가 없음을 의미하기 위해 모든 거리를 INF로 설정
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
    
    // Floyd-Warshall을 통해 모든 경로에 대한 거리 탐색 
    for (int k = 1; k <= V; k++)
        for (int i = 1; i <= V; i++)
            for (int j = 1; j <= V; j++)
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);

    // 사이클을 탐색해야 하므로 모든 (i, i)에서 최솟값 탐색
    for (int i = 1; i <= V; i++)
        answer = std::min(answer, dist[i][i]);

    // 사이클이 존재하지 않으면 -1을, 사이클이 존재하는 경우 그 최솟값을 출력
    std::cout << (answer == INF ? -1 : answer);
    return 0;
}