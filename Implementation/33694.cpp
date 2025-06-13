9#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500001

// 소환된 슬라임은 매일 크기가 증가하고, 특정 크기 이상이 되면 감소하는 패턴을 가짐
// 주어진 날에 크기가 X 이상인 슬라임이 3마리 이상인 날을 계산하여 사진을 찍을 수 있는 날 수를 구함
// 이 때, 슬라임의 크기 변화에 따라 사진을 찍을 수 있는 날의 수를 구하는 문제

typedef struct {
    long long a; // 슬라임이 증가하는 크기
    long long b; // 슬라임이 감소되는 크기
    long long c; // 슬라임이 증가할 수 있는 최대 크기
    long long t; // 슬라임이 소환되는 날짜
} info;

info slimes[MAX];
std::vector<std::pair<long long, int>> days;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N; long long X;
    std::cin >> N >> X;

    for (int i = 1; i <= N; i++) {
        std::cin >> slimes[i].a
            >> slimes[i].b
            >> slimes[i].c
            >> slimes[i].t;
    }

    for (int i = 1; i <= N; i++) {
        auto& s = slimes[i];

        // d0 : 슬라임의 크기가 c까지 도달하는 데 걸리는 날
        // d0가 정수가 아닐 수 있으므로 올림 처리를 해야 함
        // s0 : 슬라임의 크기가 a만큼 증가한 후 c에 도달했을 때의 크기(c보다 클 수 있음)
        long long d0 = (s.c + s.a - 1) / s.a;
        long long s0 = s.a * d0;
        if (s0 < X) continue;               

        // d1 : 슬라임의 크기가 X까지 도달하는 데 걸리는 날
        // L : 슬라임이 크기가 X 이상이 되는 날
        long long d1 = (X + s.a - 1) / s.a;
        long long L = s.t + d1;

        // t0 : 슬라임의 크기가 c에 도달하는 날
        // R : 슬라임의 크기가 X 이상이 끝나는 날
        long long t0 = s.t + d0;
        long long R = t0 + (s0 - X) / s.b;

        if (L <= R) {
            // days 벡터에 슬라임의 크기가 X 이상이 되는 날부터 X보다 작아지는 날까지의 이벤트가 기록됨
            // 즉 L일부터 크기가 X 이상이 되는 슬라임의 수가 증가, R+1일부터 슬라임의 크기가 X 이상이 되는 슬라임의 수가 감소
            days.emplace_back(L, 1);
            days.emplace_back(R + 1, -1);
        }
    }

    if (days.empty()) {
        std::cout << 0;
        return 0;
    }
    std::sort(days.begin(), days.end());

    long long day = 0, cnt = 0;
    long long prev = days[0].first;

    for (auto& elm : days) {
        long long cur_day = elm.first;
        int delta = elm.second;

        // 날짜가 변했을 때, 날짜 범위에 대해 슬라임 수가 3 이상이면 그 날짜 수를 더함
        // 즉 X 이상의 크기를 가진 슬라임이 셋 이상인 기간을 day에 더함
        if (cur_day > prev) {
            if (cnt >= 3)
                day += (cur_day - prev);
            prev = cur_day;
        }
        cnt += delta;
    }

    std::cout << day;
    return 0;
}
