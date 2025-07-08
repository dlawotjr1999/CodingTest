#include <iostream>
#include <vector>
#include <cmath>

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<double, double>> vec;
	for (int i = 0; i < N; ++i) {
		double x, y;
		std::cin >> x >> y;
		vec.emplace_back(x, y);
	}

	double w = 0.1;
	std::pair<double, double> center = { 0,0 };

	for (auto [x, y] : vec) {
		center.first += x / N;
		center.second += y / N;
	}

	double max_dist, radius = 0;
	std::pair<double, double> min_point;
	for (int i = 0; i < 1000000; i++) {
		max_dist = 0; 
		std::pair<double, double> max_point;

		for (auto& [x,y] : vec) {
			double dist = sqrt((center.first - x) * (center.first - x) + (center.second - y) * (center.second - y));
			if (max_dist < dist) {
				max_point = { x,y };
				max_dist = dist;
			}
		}

		center.first = center.first + (max_point.first - center.first) * w;
		center.second = center.second + (max_point.second - center.second) * w;
		w *= 0.9999;
	}

	std::cout.precision(11);
	std::cout << center.first << " " << center.second << " " << max_dist;
}