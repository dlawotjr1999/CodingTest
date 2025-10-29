#include <iostream>

// N개의 자연수로 이루어진 수열과 두 정수 S와 E가 주어짐
// 이 때, 수열의 S번째 수부터 E번째까지의 수가 팰린드롬인지를 구하는 문제

// DP[s][e] : s번 문자부터 e번 문자까지가 팰린드롬인지의 여부 
int arr[2001];
bool DP[2001][2001];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N; std::cin >> N;
    for (int i = 1; i <= N; ++i)
        std::cin >> arr[i];

    // 하나의 숫자로만 이루어진 수열은 팰린드롬
    for (int i = 1; i <= N; ++i) 
        DP[i][i] = true;

    // 두 개의 숫자로 이루어진 수열의 팰린드롬 여부 확인
    for (int i = 1; i < N; ++i) {
        if (arr[i] == arr[i + 1]) 
            DP[i][i + 1] = true;
    }

    // 어떠한 수열에서 s번 문자부터 e번 문자까지가 팰린드롬이라면 (s+1)번 문자부터 (e-1)번 문자까지도 팰린드롬
    for (int len = 3; len <= N; ++len) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;

            // DP[i + 1][j - 1]에 대해 i번 문자와 j번 문자가 동일하면 i번 문자부터 j번 문자까지도 팰린드롬
            if (arr[i] == arr[j] && DP[i + 1][j - 1]) 
                DP[i][j] = true;
        }
    }

    int M; std::cin >> M;
    while (M--) {
        int s, e; std::cin >> s >> e;
        std::cout << (DP[s][e] ? 1 : 0) << "\n";
    }
}