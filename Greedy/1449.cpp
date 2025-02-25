#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int N, L;

	std::cin >> N >> L;
	std::vector<float> pipe(N);

	for (int i = 0; i < N; i++) {
		std::cin >> pipe[i];
	}
	std::sort(pipe.begin(), pipe.end());

	int answer = 1;
	float startPos = pipe[0] - 0.5;
	float lastPos = startPos + L;

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