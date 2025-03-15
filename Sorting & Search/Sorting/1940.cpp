#include <iostream>
#include <vector>

// 투 포인터 문제
// 정렬 알고리즘으로 풀렸음. 하지만 시간 복잡도 상 투 포인터가 효율적; O(n)

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N, M;
    int cnt = 0;

    std::cin >> N >> M;

    std::vector<int> vec(N);

    for (int i = 0; i < vec.size(); i++) {
        std::cin >> vec[i];
    }

    // 선택 정렬 알고리즘과 방식이 일치;
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] + vec[j] == M)
                cnt++;
        }
    }

    std::cout << cnt;

    return 0;
}