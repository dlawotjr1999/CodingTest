#include <bits/stdc++.h>

// 기존의 큐와 달리 중요도를 고려하는 '프린터 큐'를 만들고자 하며, 이는 아래 규칙을 따름
// - 현재 Queue의 가장 앞에 있는 문서의‘중요도’를 확인함
// - 나머지 문서들 중 현재 문서보다 중요도가 높은 문서가 하나라도 있다면, 이 문서를 인쇄하지 않고 Queue의 가장 뒤에 재배치 하며, 그렇지 않다면 바로 인쇄를 함
// 이 때, M번째 문서가 몇 번째로 인쇄되는지를 구하는 문제

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int N, M;
        std::cin >> N >> M;

        std::queue<std::pair<int, int>> q; 
        std::priority_queue<int> pq; 

        // 큐에는 중요도와 인덱스를, 우선순위 큐에는 순위들만 삽입
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

            // 큐의 중요도와 우선순위 큐의 값이 일치한다면 우선순위 큐에서 값을 제거
            // 만약 찾고자 하는 큐의 값이었다면 출력하고 종료
            // 반대로 큐의 중요도와 우선순위 큐의 값이 다르다면 pop했던 값을 다시 큐의 맨 뒤에 삽입함
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