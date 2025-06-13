9#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500001

// ��ȯ�� �������� ���� ũ�Ⱑ �����ϰ�, Ư�� ũ�� �̻��� �Ǹ� �����ϴ� ������ ����
// �־��� ���� ũ�Ⱑ X �̻��� �������� 3���� �̻��� ���� ����Ͽ� ������ ���� �� �ִ� �� ���� ����
// �� ��, �������� ũ�� ��ȭ�� ���� ������ ���� �� �ִ� ���� ���� ���ϴ� ����

typedef struct {
    long long a; // �������� �����ϴ� ũ��
    long long b; // �������� ���ҵǴ� ũ��
    long long c; // �������� ������ �� �ִ� �ִ� ũ��
    long long t; // �������� ��ȯ�Ǵ� ��¥
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

        // d0 : �������� ũ�Ⱑ c���� �����ϴ� �� �ɸ��� ��
        // d0�� ������ �ƴ� �� �����Ƿ� �ø� ó���� �ؾ� ��
        // s0 : �������� ũ�Ⱑ a��ŭ ������ �� c�� �������� ���� ũ��(c���� Ŭ �� ����)
        long long d0 = (s.c + s.a - 1) / s.a;
        long long s0 = s.a * d0;
        if (s0 < X) continue;               

        // d1 : �������� ũ�Ⱑ X���� �����ϴ� �� �ɸ��� ��
        // L : �������� ũ�Ⱑ X �̻��� �Ǵ� ��
        long long d1 = (X + s.a - 1) / s.a;
        long long L = s.t + d1;

        // t0 : �������� ũ�Ⱑ c�� �����ϴ� ��
        // R : �������� ũ�Ⱑ X �̻��� ������ ��
        long long t0 = s.t + d0;
        long long R = t0 + (s0 - X) / s.b;

        if (L <= R) {
            // days ���Ϳ� �������� ũ�Ⱑ X �̻��� �Ǵ� ������ X���� �۾����� �������� �̺�Ʈ�� ��ϵ�
            // �� L�Ϻ��� ũ�Ⱑ X �̻��� �Ǵ� �������� ���� ����, R+1�Ϻ��� �������� ũ�Ⱑ X �̻��� �Ǵ� �������� ���� ����
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

        // ��¥�� ������ ��, ��¥ ������ ���� ������ ���� 3 �̻��̸� �� ��¥ ���� ����
        // �� X �̻��� ũ�⸦ ���� �������� �� �̻��� �Ⱓ�� day�� ����
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
