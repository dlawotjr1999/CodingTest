#include <bits/stdc++.h>

double answer;

int main() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> vec(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i].first >> vec[i].second;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            for (int k = j + 1; k < N; ++k) {
                long long x1 = vec[j].first - vec[i].first;
                long long y1 = vec[j].second - vec[i].second;
                long long x2 = vec[k].first - vec[i].first;
                long long y2 = vec[k].second - vec[i].second;

                double area = std::llabs(x1 * y2 - y1 * x2) * 0.5;
                answer = std::max(answer, area);
            }
        }
    }

    std::cout.setf(std::ios::fixed);
    std::cout.precision(12);
    std::cout << answer;
    return 0;
}