#include <iostream>
#include <vector>
#include <queue>

// ��ӵ��θ� Ÿ�� D�� ���̸� ������ ��, �������� Ÿ�� ������ �� ��쿡 �ּ� ���� �Ÿ��� ���ϴ� ���� 

constexpr int INF = 1e6;

int main() {
    int N, D;
    std::cin >> N >> D;

    std::vector<std::vector<std::pair<int, int>>> roads(D + 1);
    std::vector<int> dist(D + 1, INF);

    // ��� ������ ���� �Ÿ��� 1�� �ʱ�ȭ
    for (int i = 0; i < D; i++) {
        roads[i].emplace_back(i + 1, 1);  
    }

    for (int i = 0; i < N; ++i) {
        int start, end, len;
        std::cin >> start >> end >> len;

        // ��ȿ�� ���� ������, �������� ��쿡�� vector�� ����
        if (start < 0 || end > D || start >= end) 
            continue;
        if (len >= (end - start)) 
            continue;
        roads[start].emplace_back(end, len);  
    }

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;

    dist[0] = 0;
    pq.emplace(0, 0); 

    // �ִ� �Ÿ��� D�� �ʱ�ȭ. ���� Dijkstra �˰����� ���� �Ÿ��� ���ŵ�
    int answer = D; 
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();

        if (cost > dist[cur]) continue;

        // ���� �Ÿ��� ���ŵ� �Ÿ��� �� ���� ������ ����
        // ���ŵ� �Ÿ� : �������� ���� �̵��� �Ÿ� + ���� �Ÿ�(���� ���� ���� - �������� ���� �̵��� ���� ����)
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