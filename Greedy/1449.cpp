#include <iostream>
#include <vector>
#include <algorithm>

// N개의 물이 새는 곳(정수 위치)이 주어진다
// 길이가 L인 테이프를 이용해 물이 새는 곳을 막아야 한다
// 하나의 테이프는 L 길이 내에서 여러 개의 구멍을 막을 수 있다
// 이 때 필요한 최소 테이프 개수를 구하는 문제

int main() {
	int N, L;

	std::cin >> N >> L;
	std::vector<float> pipe(N);

	for (int i = 0; i < N; i++) {
		std::cin >> pipe[i];
	}

	// 테이프를 최대한 적게 사용하려면 가장 앞쪽부터 막아야 하므로 정렬을 수행
	std::sort(pipe.begin(), pipe.end());

	// 하나의 테이프로 커버할 수 있는 범위를 구해야 함
	int answer = 1;
	float startPos = pipe[0] - 0.5;
	float lastPos = startPos + L;

	// 하나의 테이프로 커버된 길이보다 물이 새는 위치가 더 뒤에 있으면 이 때 테이프를 추가로 사용한다
	// 이 때 시작점과 끝점의 위치를 갱신해야 한다
	for (int i = 1; i < N; i++) {
		if (pipe[i] > lastPos) {
			startPos = pipe[i] - 0.5;
			lastPos = startPos + L;
			answer++;
		}
	}

	std::cout << answer;

	return 0;
}