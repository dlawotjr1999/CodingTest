#include <iostream>
#include <vector>

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

    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] + vec[j] == M)
                cnt++;
        }
    }

    std::cout << cnt;

    return 0;
}