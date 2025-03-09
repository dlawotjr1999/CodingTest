#include <iostream>
#include <vector>
#include <algorithm>

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

        for (int i = (vec.size() - 1); i >= 0; i--) {
            if (maxValue < vec[i])
                maxValue = vec[i];
            else
                profit += (maxValue - vec[i]);
        }
        std::cout << profit << std::endl;
    }

    return 0;
}
