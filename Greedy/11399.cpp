#include <iostream>
#include <vector>
#include <algorithm>

// 줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 P_i가 주어졌을 때, 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 문제
// 대기시간이 짧은 순서의 사람부터 앞으로 서있어야(오름차순) 그 대기시간이 최소가 됨
int main() {
    int N, elm, result = 0;

    std::vector<int> vec;

    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::cin >> elm;
        vec.push_back(elm);
    }

    // 최소 대기시간을 만들기 위해 정렬을 수행해야 함
    std::sort(vec.begin(), vec.end());

    for (int i = 0; i < N; i++) {
        result += vec[i] * (N - i);
    }
    std::cout << result;

    return 0;
}
