#include <iostream>
#include <vector>
#include <algorithm>

// 1분에 한 번씩 두 집을 선택해서 두 집 앞의 눈을 각각 1만큼 치우거나, 한 집을 선택해서 그 집 앞의 눈을 1만큼 치울 수 있다.
// 이 때 모든 집 앞의 눈을 전부 치울 때까지 걸리는 최소 시간을 구하는 문제
// 24시간이 넘는 경우에는 -1 출력
// idea : 가장 눈이 많이 쌓인 두 집 앞의 눈을 치워나가면 최소 시간을 구할 수 있음

int cnt;

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec;
	for (int i = 0; i < N; i++) {
		int snow; std::cin >> snow;
		vec.push_back(snow);
	}

	// 눈이 가장 많이 쌓인 집을 구하기 위해 정렬 수행
	std::sort(vec.rbegin(), vec.rend());

	while (vec[0] > 0) {
		
		// 집이 한 채 이상이고, 각 집의 눈이 쌓여있을 경우에 눈을 치운다
		if (N > 1) {
			if (vec[0] > 0)
				vec[0]--;
			if (vec[1] > 0)
				vec[1]--;
		}
		else {
			vec[0]--;
		}
		cnt++;

		// 다시 정렬을 수행하여 가장 큰 값을 앞부분에 계속 위치시킨다. 이를 반복해나감
		std::sort(vec.rbegin(), vec.rend());
	}

	if (cnt > 1440)
		cnt = -1;
	std::cout << cnt;

	return 0;
}