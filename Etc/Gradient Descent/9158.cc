#include <bits/stdc++.h>

// N개의 별들을 포함하는 "Super Star"라는 가상의 구가 있을 때, 이 "Super Start"의 최소 반지름을 구하는 문제
// 2389번 문제와 동일한 알고리즘 사용(3차원으로 확장)

struct Point {
    double x, y, z;
    Point(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}
};

int main() {
    while (true) {
        int N;
        std::cin >> N;

        if (N == 0)
            break;

        std::vector<Point> vec;
        for (int i = 0; i < N; ++i) {
            double x, y, z;
            std::cin >> x >> y >> z;
            vec.emplace_back(x, y, z);
        }

        double w = 0.1;
        Point center(0, 0, 0);

        for (const Point& point : vec) {
            center.x += point.x / N;
            center.y += point.y / N;
            center.z += point.z / N;
        }

        double max_dist = 0;
        int idx = 0;

        for (int i = 0; i < 50000; i++) {
            max_dist = 0;

            for (int j = 0; j < N; j++) {
                double cur_distance = sqrt((center.x - vec[j].x) * (center.x - vec[j].x) +
                    (center.y - vec[j].y) * (center.y - vec[j].y) +
                    (center.z - vec[j].z) * (center.z - vec[j].z));
                if (cur_distance > max_dist) {
                    max_dist = cur_distance;
                    idx = j;
                }
            }

            center.x += (vec[idx].x - center.x) * w;
            center.y += (vec[idx].y - center.y) * w;
            center.z += (vec[idx].z - center.z) * w;

            w *= 0.999;
        }

        // 부동소수점 오차로 인한 "−0.00" 출력 방지용 보정
        if (round(center.x) == 0) center.x = 0;
        if (round(center.y) == 0) center.y = 0;
        if (round(center.z) == 0) center.z = 0;

        std::cout << std::fixed << std::setprecision(5) << max_dist << '\n';
    }

    return 0;
}
