#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N; std::cin >> N;

    std::vector<int> positives;
    std::vector<int> negatives;
    long long answer = 0;
    int zero_cnt = 0;

    for (int i = 0; i < N; ++i) {
        int v;
        std::cin >> v;
        if (v > 1) 
            positives.push_back(v);
        else if (v == 1) 
            answer++;
        else if (v == 0)
            zero_cnt++;
        else 
            negatives.push_back(v);
    }

    std::sort(positives.begin(), positives.end(), std::greater<int>());
    for (size_t i = 0; i + 1 < positives.size(); i += 2) {
        answer += 1LL * positives[i] * positives[i + 1];
    }
    if (positives.size() % 2 == 1) 
        answer += positives.back();

    std::sort(negatives.begin(), negatives.end());
    for (size_t i = 0; i + 1 < negatives.size(); i += 2) {
        answer += 1LL * negatives[i] * negatives[i + 1];
    }
    if (negatives.size() % 2 == 1) {
        if (zero_cnt == 0) 
            answer += negatives.back();
    }

    std::cout << answer;
    return 0;
}