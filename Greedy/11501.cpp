#include <iostream>
#include <vector>
#include <algorithm>

// 날의 수를 나타내는 자연수 N이 주어지고, 날 별 주가를 나타내는 N개의 자연수들이 공백으로 구분되어 순서대로 주어진다.
// 이 때 최대 이익을 나타내는 정수를 출력한다

int main() {
    std::cin.tie(NULL);
    std::ios::sync_with_stdio(false);

    int T;
    std::cin >> T;

    while (T--) {
        int N;
        std::cin >> N;

        std::vector<int> vec(N);

        for (int& elm : vec) {
            std::cin >> elm;
        }

        int maxValue = 0;
        long long profit = 0;

        // idea : 역순으로 검토해야 답을 도출할 수 있음
        // 역순으로 검토하면서 maxValue를 갱신해나감
        // maxValue보다 작은 값들은 지나가며, maxValue보다 큰 값이 있으면 maxValue를 그 값으로 설정함
        // maxValue보다 작은 값들은 maxValue에서 각 값을 뺀 수치(즉, 그 날의 수익을 의미함)를 더하면서 총 수익을 계산해나감
        for (int i = (vec.size() - 1); i >= 0; i--) {
            if (maxValue < vec[i])
                maxValue = vec[i];
            else
                profit += (maxValue - vec[i]);
        }

        // diffrent access(iterator 사용)
        /* 
        int maxValue = vec.back();
        long long profit = 0;

        for (auto it = vec.crbegin(); it != vec.crend(); it++) {
            if (maxValue < *it)
                maxValue = *it;
            else
                profit += (maxValue - *it);
        }
        */
        std::cout << profit << std::endl;
    }

    return 0;
}
