#include <iostream>
#include <algorithm>

// 매일 약을 복용하고자 할 때, 아래 규칙에 따라 복용하고자 함
// 1. 첫째 날에는 병에서 약을 하나 꺼내고, 그 약을 반으로 쪼개서 한 조각은 먹고 다른 조각은 다시 병에 넣음
// 2. 다음 날부터 꺼낸 약이 반 조각이면 먹고, 아니라면 반을 쪼개 한 조각을 먹고 다른 조각은 다시 병에 넣음
// 3. 한 조각을 꺼낸 날에는 W를, 반 조각을 꺼낸 날에는 H를 기록함. 즉 2N일이 지나면 2N 길이의 문자열이 만들어짐
// 이 때, 가능한 서로 다른 문자열의 갯수를 구하는 문제

// 참고 : 카탈랑 수(https://ko.wikipedia.org/wiki/%EC%B9%B4%ED%83%88%EB%9E%91_%EC%88%98)

int main() {
    // DP[i][j] : 온전한 알약 i개와 반쪽짜리 알약 j개를 먹을 수 있는 경우의 수 
    long long DP[31][31] = { 0 };

    for (int w = 0; w <= 30; ++w)
        DP[0][w] = 1;

    // W와 H로 표현할 수 있는 길이 n의 문자열 = 길이가 (n-1)인 문자열의 + W or H
    // 단, 문제 조건에 의해 어떠한 경우는 w >= h을 만족해야 함
    // 또한 tabulation 진행 시, 아래와 같은 점화식을 유도할 수 있음
    // arr[i][j] = arr[i - 1][j] + arr[i][j - 1]
    for (int h = 1; h <= 30; ++h) {
        for (int w = h; w <= 30; ++w) {
            DP[w][h] = DP[w - 1][h] + DP[w][h - 1];
        }
    }
 
    while (true) {
        int N;
        std::cin >> N;

        if (N == 0)
            break;

        // DP[N][N]에 2N 길이의 서로 다른 문자열의 갯수가 저장됨
        std::cout << DP[N][N] << '\n';
    }

    return 0;
}
