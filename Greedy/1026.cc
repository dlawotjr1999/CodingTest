#include <iostream>
#include <vector>
#include <algorithm>

// 길이가 N인 정수 배열 A와 B가 있을 때, 함수 S는 아래와 같이 정의됨
// S = A[0] × B[0] + ... + A[N - 1] × B[N - 1]
// 이 때 A를 재배열하여 S의 최솟값을 구하는 문제 
// 단, B에 있는 수는 재배열하면 안 됨

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    // A를 배열한다는 뜻은 곧 A의 배열 순서가 마음대로 바뀔 수 있다는 것을 의미함
    // 결과적으로 순서를 원하는 것이 아니기 때문에 B를 재배열해도 무방함(원래의 B를 통해 최솟값을 만들 수 있도록 A의 값들을 대응시키면 됨) 
    // S를 최소화하려면 A는 작은 수부터, B는 큰 수부터 정렬하여 값을 구하면 됨

    // A는 오름차순으로, B는 내림차순으로 정렬
    std::sort(A.begin(), A.end());
    std::sort(B.begin(), B.end(), std::greater<int>());

    long long S = 0;
    for (int i = 0; i < N; i++) {
        S += 1LL * A[i] * B[i];
    }

    std::cout << S << "\n";
    return 0;
}
