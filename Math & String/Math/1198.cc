#include <bits/stdc++.h>

// 볼록 다각형이 있고, 여기서 3개의 연속된 점을 선택해서 삼각형을 만든 후, 만든 삼각형을 다각형에서 제외하고자 함 
// 즉 원래 다각형이 N개의 점이 있었다면, 이제 N - 1개의 점으로 구성된 볼록 다각형이 됨
// 위의 과정을 남은 다각형이 삼각형이 될 때까지 반복할 때, 가능한 넓이의 최댓값을 구하는 문제

double answer;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> vec(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i].first >> vec[i].second;
    }

    // 즉 N개의 점 중 3개를 선택하여 만들 수 있는 삼각형의 최댓값을 구하면 됨
    // 세 좌표들의 조합을 탐색
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                long long x1 = vec[j].first - vec[i].first;
                long long y1 = vec[j].second - vec[i].second;
                long long x2 = vec[k].first - vec[i].first;
                long long y2 = vec[k].second - vec[i].second;

                // 외적을 통해 삼각형의 넓이를 구함
                double area = std::llabs(x1 * y2 - y1 * x2) * 0.5;
                answer = std::max(answer, area);
            }
        }
    }

    // 오차 범위 보정
    std::cout.setf(std::ios::fixed);
    std::cout.precision(12);
    std::cout << answer;
    return 0;
}