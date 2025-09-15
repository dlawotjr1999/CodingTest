#include <iostream>
#include <vector>
#include <queue>

// 고속도로를 타고 D의 길이를 운전할 때, 지름길을 타고 운전을 할 경우에 최소 운전 거리를 구하는 문제 

constexpr int INF = 1e6;

int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<std::vector<std::pair<int, int>>> roads(D + 1);
    std::vector<int> dist(D + 1, INF);

    // 모든 지점에 대해 거리를 1로 초기화
    for (int i = 0; i < D; i++) {
        roads[i].emplace_back(i + 1, 1);  
    }

    for (int i = 0; i < N; ++i) {
        int start, end, len;
        std::cin >> start >> end >> len;

        // 유효한 범위 내에서, 지름길인 경우에만 vector에 저장
        if (start < 0 || end > D || start >= end) 
            continue;
        if (len >= (end - start)) 
            continue;
        roads[start].emplace_back(end, len);  
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[0] = 0;
    pq.emplace(0, 0); 

    // 최대 거리인 D로 초기화. 이후 Dijkstra 알고리즘을 통해 거리가 갱신됨
    int answer = D; 
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur]) continue;

        // 현재 거리와 갱신된 거리의 중 작은 값으로 갱신
        // 갱신된 거리 : 지름길을 통해 이동한 거리 + 남은 거리(최종 도착 지점 - 지름길을 통해 이동한 현재 지점)
        answer = std::min(answer, cost + (D - cur));

        for (const auto& [next_node, next_cost] : roads[cur]) {
            int new_cost = cost + next_cost;
            if (new_cost < dist[next_node]) {
                dist[next_node] = new_cost;
                pq.emplace(new_cost, next_node);
            }
        }
    }

    std::cout << answer;
    return 0;
}