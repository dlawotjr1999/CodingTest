#include <bits/stdc++.h>

// ������ ť�� �޸� �߿䵵�� ����ϴ� '������ ť'�� ������� �ϸ�, �̴� �Ʒ� ��Ģ�� ����
// - ���� Queue�� ���� �տ� �ִ� �����ǡ��߿䵵���� Ȯ����
// - ������ ������ �� ���� �������� �߿䵵�� ���� ������ �ϳ��� �ִٸ�, �� ������ �μ����� �ʰ� Queue�� ���� �ڿ� ���ġ �ϸ�, �׷��� �ʴٸ� �ٷ� �μ⸦ ��
// �� ��, M��° ������ �� ��°�� �μ�Ǵ����� ���ϴ� ����

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N, M;
        std::cin >> N >> M;

        std::queue<std::pair<int, int>> q; 
        std::priority_queue<int> pq; 

        // ť���� �߿䵵�� �ε�����, �켱���� ť���� �����鸸 ����
        for (int i = 0; i < N; ++i) {
            int priority;
            std::cin >> priority;
            q.emplace(priority, i);
            pq.push(priority);
        }

        int cnt = 0;
        while (!q.empty()) {
            int cur_priority = q.front().first;
            int idx = q.front().second;
            q.pop();

            // ť�� �߿䵵�� �켱���� ť�� ���� ��ġ�Ѵٸ� �켱���� ť���� ���� ����
            // ���� ã���� �ϴ� ť�� ���̾��ٸ� ����ϰ� ����
            // �ݴ�� ť�� �߿䵵�� �켱���� ť�� ���� �ٸ��ٸ� pop�ߴ� ���� �ٽ� ť�� �� �ڿ� ������
            if (cur_priority == pq.top()) {
                cnt++;
                pq.pop();

                if (idx == M) {
                    std::cout << cnt << '\n';
                    break;
                }
            }
            else {
                q.emplace(cur_priority, idx); 
            }
        }
    }

    return 0;
}