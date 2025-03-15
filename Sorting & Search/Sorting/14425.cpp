#include <iostream>
#include <vector>
#include <algorithm>

// 단순 이분탐색 문제(자료형이 string일 뿐)

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N, M;
    int cnt = 0;

    std::cin >> N >> M;
    std::vector<std::string> Set;

    for (int i = 0; i < N; i++) {
        std::string input;
        std::cin >> input;
        Set.push_back(input);
    }

    std::sort(Set.begin(), Set.end());

    for (int j = 0; j < M; j++) {
        std::string input2;
        std::cin >> input2;

        if (std::binary_search(Set.begin(), Set.end(), input2))
            cnt++;
    }

    std::cout << cnt;

    return 0;
}