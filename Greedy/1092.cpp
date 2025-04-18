#include <iostream>
#include <vector>
#include <algorithm>

// 항구에는 크레인이 N대 있고, 1분에 박스를 하나씩 배에 실을 수 있다. 또한 모든 크레인은 동시에 움직인다.
// 각 크레인은 무게 제한이 있으며 이 무게 제한보다 무거운 박스는 크레인으로 움직일 수 없다. 
// 이 때 모든 박스를 배로 옮기는데 드는 시간의 최솟값을 구하는 문제

int minute;

int main() {
	int N, M;
	std::cin >> N;
	std::vector<int> crains(N);

	for (int i = 0; i < N; i++) {
		std::cin >> crains[i];
	}

	std::cin >> M;
	std::vector<int> items(M);

	for (int i = 0; i < M; i++) {
		std::cin >> items[i];
	}

	std::sort(crains.rbegin(), crains.rend());
	std::sort(items.rbegin(), items.rend());

	// 오름차순으로 정렬이 되었을 때, 가장 앞의 크레인이 가장 무거운 박스를 들지 못한다면 다른 크레인들 역시 그 박스를 옮길 수 없음
	// 즉 모든 크레인들에 대해서 모든 박스들을 옮길 수 없음
	if (crains[0] < items[0]) {
		std::cout << -1;
		return 0;
	}

	// moved: 옮겨진 박스의 갯수
	// idx: 현재 처리 중인 박스를 가리키는 인덱스
	int moved = 0;

	// 박스를 모두 옮길 때까지 반복
	while (moved < M) {
		int idx = 0;

		// 각 크레인에 대해 반속
		for (int i = 0; i < N; i++) {
			// 현재 크레인이 옮길 수 있는 박스를 찾을 때까지 반복
			while (idx < M) {
				// 크레인이 박스를 옮길 수 있는 경우
				if (items[idx] != -1 && crains[i] >= items[idx]) {
					// 박스를 옮기면 -1로 저장
					items[idx] = -1;
					// 옮긴 박스 수 증가, 다음 박스를 확인
					moved++; idx++;
					break;
				}
				// 크레인이 박스를 옮기지 못하는 경우, 다음 박스를 확인 (박스는 무게가 적은 순서로 옮겨지므로 idx++로 진행)
				idx++;
			}
		}
		minute++;
	}
	std::cout << minute;

	return 0;
}