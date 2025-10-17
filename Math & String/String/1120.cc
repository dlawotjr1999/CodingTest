#include <bits/stdc++.h>

// 두 문자열 A와 B가 있을 때(A의 길이 <= B의 길이), A의 앞이나 뒤에 아무 알파벳을 추가할 수 있음
// 이 때, A와 B의 길이가 같으면서, A와 B의 차이의 최솟값을 구하는 문제

int main() {
    std::string A, B;
    std::cin >> A >> B;

    int diff = INT_MAX;

    // 두 문자열의 길이 차이만큼 반복하며 검사
    for (int i = 0; i <= B.size() - A.size(); i++) {
        int cur = 0;

        // 각 위치에서 다른 문자의 갯수를 센 뒤, 최솟값을 갱신해나감
        for (int j = 0; j < A.size(); j++) {
            if (A[j] != B[i + j]) cur++;
        }
        diff = std::min(diff, cur);
    }

    std::cout << diff << "\n";
    return 0;
}