#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

// 산술평균, 중앙값, 최빈값, 범위 구하기
// 산술평균 : N개의 수들의 합을 N으로 나눈 값
// 중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
// 최빈값 : N개의 수들 중 가장 많이 나타나는 값. 여러 개 있을 때에는 최빈값 중 두 번째로 작은 값을 출력한다.
// 범위 : N개의 수들 중 최댓값과 최솟값의 차이

int main() {
    int N, sum = 0;
    std::cin >> N;

    std::vector<int> vec(N);
    std::unordered_map<int, int> freq;  // 최빈값을 구하기 위한 map

    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
        sum += vec[i];  // 산술평균을 구하기 위함
        freq[vec[i]]++; // 최빈값을 구하기 위해 map을 이용. 중복 입력 시 vec[i]의 value를 증가시킴 
    }

    std::sort(vec.begin(), vec.end());

    int size = vec.size();

    int mean = std::round(static_cast<double>(sum) / size); // 산술평균
    int center = vec[size / 2];                             // 중앙값

    // 최빈값 구하기
    // 정렬을 위해 map을 pair를 이용한 vector로 변환
    std::vector<std::pair<int, int>> temp(freq.begin(), freq.end());
    // value, 즉 빈도수에 따라 정렬, 만약 빈도수가 같다면 더 작은 수가 앞에 위치하도록 함
    std::sort(temp.begin(), temp.end(), [](auto const& l, auto const& r)
        {
            return l.second != r.second ? l.second > r.second : l.first < r.first;
        });
    int mode = temp[0].first;

    // 두 번째로 작은 값을 최빈값으로 함
    if (temp.size() > 1 && temp[0].second == temp[1].second)
        mode = temp[1].first;

    int range = vec[size - 1] - vec[0]; // 범위

    std::cout << mean << '\n' << center << '\n' << mode << '\n' << range << '\n';

    return 0;
}
