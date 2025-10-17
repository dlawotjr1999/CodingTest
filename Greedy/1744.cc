#include <iostream>
#include <vector>
#include <algorithm>

// 수열을 구성하는 수들을 두 개씩 묶어 곱한 후, 그 합의 최댓값을 구하는 문제
// 수들은 위치에 상관없이 묶을 수 있지만 같은 위치에 있는 수를 묶을 수는 없음
// 또한 수열의 모든 수는 단 한 번만 묶거나, 묶지 않아야 함

int main() {
    int N; std::cin >> N;

    std::vector<int> positives;
    std::vector<int> negatives;
    long long answer = 0;
    int zero_cnt = 0;

    // 양수와 음수를 나누어서 저장
    // 1은 곱하는 것보다 더하는 것이 총 누계를 더 크게 만들 수 있으므로 합산으로만 계산
    // 음수의 합을 계산하기 위해 0의 갯수 필요
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

    // 양수는 내림차순으로 정렬하여 두 개씩 묶어 곱하면서 합산
    // 만약 양수의 갯수가 홀수 개이면 마지막에 있는 원소(가장 작은 양수)는 더하기만 하면 됨
    std::sort(positives.begin(), positives.end(), std::greater<int>());
    for (size_t i = 0; i + 1 < positives.size(); i += 2) {
        answer += 1LL * positives[i] * positives[i + 1];
    }
    if (positives.size() % 2 == 1) 
        answer += positives.back();

    // 음수는 오름차순으로 정렬하여 두 개씩 묶어 곱하면서 합산
    // 만약 음수의 갯수가 홀수 개이면, 0이 홀수 개 일 때 마지막 요소를 더하기만 하면 됨
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