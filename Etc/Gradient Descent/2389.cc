#include <iostream>
#include <vector>
#include <cmath>

// 원형 모양의 콘서트홀을 만들고자 할 때 팬들의 위치 좌표들을 통해, 홀에 모든 팬들을 포함할 수 있도록 홀의 최소 반지름을 계산하는 문제
// 최소 외접원 문제를 경사 하강법으로 구현

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<double, double>> vec;
	for (int i = 0; i < N; ++i) {
		double x, y;
		std::cin >> x >> y;
		vec.emplace_back(x, y);
	}

	// 최초 가중치는 10%로 설정
	double w = 0.1;
	std::pair<double, double> center = { 0,0 };

	// 좌표들의 평균 위치를 계산
	for (auto [x, y] : vec) {
		center.first += x / N;
		center.second += y / N;
	}

	double max_dist, radius = 0;
	std::pair<double, double> min_point;

	// 아래의 연산들을 반복하면, 중심 좌표는 최소 외접원의 중심에 근사하게 됨
	for (int i = 0; i < 1000000; i++) {
		max_dist = 0; 
		std::pair<double, double> max_point;

		// 현재 중심 좌표(점들의 평균 위치에 근사함)에서 가장 멀리 떨어진 좌표와 그 거리를 구함
		for (auto& [x,y] : vec) {
			double dist = sqrt((center.first - x) * (center.first - x) + (center.second - y) * (center.second - y));
			if (max_dist < dist) {
				max_point = { x,y };
				max_dist = dist;
			}
		}

		// 중심 좌표는 가장 먼 거리에 위치해 있는 좌표의 10% 길이를 가지는 위치의 좌표로 갱신
		// 이후 가중치 갱신
		center.first = center.first + (max_point.first - center.first) * w;
		center.second = center.second + (max_point.second - center.second) * w;
		w *= 0.9999;
	}

	std::cout.precision(11);
	std::cout << center.first << " " << center.second << " " << max_dist;
}