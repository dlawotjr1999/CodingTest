#include <iostream>
#include <vector>

// N개의 운동 키트가 주어지고, 각 키트는 특정 무게만큼 근손실을 막아줌(중량 증가).
// 매일 1개씩 키트를 사용해서 K만큼 중량 감소 후, 해당 키트의 무게만큼 다시 증가함
// N일 동안 사용 순서를 정했을 때, 중량이 하루라도 500 미만으로 떨어지지 않는 경우의 수를 구하는 문제

int N, K;
int cnt;

std::vector<int> vec;
bool visited[9];

void DFS(int day, int weight) {

    // N일동안 진행하였을 때, 몸무게가 500 이상인 조합인 경우에 cnt 증가
    if (day == N && weight >= 500) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i])
            continue;
        visited[i] = true;

        // 현재 몸무게에서 한 키트의 운동을 했을 때의 증가하는 중량과 하루에 빠지는 중량(K)을 고려해서 탐색 
        if (weight + vec[i] - K >= 500)
            DFS(day + 1, weight + vec[i] - K);
        visited[i] = false;
    }
}

int main() {
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int elm;
        std::cin >> elm;
        vec.push_back(elm);
    }

    DFS(0, 500);
    std::cout << cnt;

    return 0;
}
