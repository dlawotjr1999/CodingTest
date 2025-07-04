#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

// N개의 원소들로 이루어진 배열 A가 주어져 있을 때 원소들의 순서를 바꿔 아래 수식의 최댓값을 구하는 문제
// | A[0] - A[1] | +| A[1] - A[2] | +... + | A[N - 2] - A[N - 1] |

int main() {
    int N;
    std::cin >> N;

    std::vector<int> vec(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> vec[i];
    }

    // next_permutation을 위해 정렬 먼저 수행
    std::sort(vec.begin(), vec.end());
    
    // next_permutaion 함수는 다음 순열이 존재하면 해당 순열 순서로 바꾸고 true로 반환함
    // 즉 최초 순열에 대한 계산이 선행되어야 하기 때문에 do-while문을 통해 구현해야 함
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