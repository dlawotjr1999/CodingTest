#include <iostream>
#include <vector>
#include <queue>

std::vector<int> trucks;
std::queue<int> bridge;

int main() {
	int n, w, L;
	std::cin >> n >> w >> L;

	trucks.resize(n);
	for (int& truck : trucks) {
		std::cin >> truck;
	}

	int time = 0;
	int truck_weights = 0;
	int idx = 0;

	while (idx < n || truck_weights > 0) {
		time++;

		if (bridge.size() == w) {
			truck_weights -= bridge.front();
			bridge.pop();
		}
		if (idx < n && truck_weights + trucks[idx] <= L) {
			bridge.push(trucks[idx]);
			truck_weights += trucks[idx];
			idx++;
		}
		else {
			bridge.push(0);
		}
	}

	std::cout << time;
	return 0;
}