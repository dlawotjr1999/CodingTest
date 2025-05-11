#include <iostream>
#include <vector>
#include <queue>

// 다리 길이 W, 최대 하중 L, N대의 트럭 무게가 주어질 때, 대기 중인 트럭이 순서대로 다리를 건너는 데 걸리는 최소 시간을 구하는 문제
// 매 초마다 트럭은 다리 위를 한 칸씩 이동하며, 다리 위 트럭들의 무게 합이 L을 넘지 않아야 함

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

	// 모든 트럭이 통과하고, 다리 위에 트럭이 없을 때까지 반복
	// 남은 트럭 처리와 다리 위 트럭 완전 통과 두 조건을 모두 만족시키기 위해 OR 사용
	while (idx < n || truck_weights > 0) {
		time++;

		// 다리 위에 올린(큐에 넣은) 칸이 다리 길이(w)와 같아지면
		// 맨 앞에 있던 트럭이 다리를 통과한 것
		if (bridge.size() == w) {
			truck_weights -= bridge.front();
			bridge.pop();
		}

		// 아직 대기 중인 트럭이 남아있고,
		// 다음 트럭을 올렸을 때 다리 최대 하중(L)을 넘지 않으면 다리에 트럭 진입
		if (idx < n && truck_weights + trucks[idx] <= L) {
			bridge.push(trucks[idx]);
			truck_weights += trucks[idx];
			idx++;
		}
		
		// 진입 불가 시 빈 칸(0)을 넣어 시간만 흐르게 함
		else {
			bridge.push(0);
		}
	}

	std::cout << time;
	return 0;
}