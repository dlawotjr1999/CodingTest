#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N, M;
        std::cin >> N >> M;

        std::queue<std::pair<int, int>> q; 
        std::priority_queue<int> pq; 

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