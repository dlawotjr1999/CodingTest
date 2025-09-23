#include <bits/stdc++.h>

int main() {
    std::string A, B;
    std::cin >> A >> B;

    int diff = INT_MAX;

    for (int i = 0; i <= B.size() - A.size(); i++) {
        int cur = 0;

        for (int j = 0; j < A.size(); j++) {
            if (A[j] != B[i + j]) cur++;
        }
        diff = std::min(diff, cur);
    }

    std::cout << diff << "\n";
    return 0;
}