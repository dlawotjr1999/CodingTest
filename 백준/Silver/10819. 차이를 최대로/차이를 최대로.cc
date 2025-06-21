#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());
    
    int answer = 0;
    do {
        int sum = 0;
        for (int i = 0; i < N - 1; ++i) {
            sum += std::abs(vec[i] - vec[i + 1]);
        }
        answer = std::max(answer, sum);
    } while (std::next_permutation(vec.begin(), vec.end()));

    std::cout << answer << '\n';
    return 0;
}