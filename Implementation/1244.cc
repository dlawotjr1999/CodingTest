#include <iostream>
#include <vector>

// 참고 : https://www.acmicpc.net/problem/1244
// 위 시뮬레이션을 구현하는 문제

int main() {
	int N;
	std::cin >> N;

	std::vector<bool> switches;
	for (int i = 0; i < N; ++i) {
		bool elm;
		std::cin >> elm;
		switches.push_back(elm);
	}

	int cmd_num;
	std::cin >> cmd_num;

	for (int i = 0; i < cmd_num; ++i) {
		int a, b;
		std::cin >> a >> b;

		// 남학생은 자신이 뽑은 수의 배수의 인덱스에 해당하는 스위치만 토글함
		if (a == 1) {
			for (int j =  b - 1; j < N; j += b) {
				switches[j] = !switches[j];
			}
		}

		// 여학생은 자신이 뽑은 수를 기준으로 양 옆의 스위치들을 탐색함
		// 두 스위치의 상태가 동일한 인덱스들의 스위치들만 토글함 
		else {
			int idx = b - 1;
			switches[idx] = !switches[idx];

			int l = idx - 1, r = idx + 1;
			while (l >= 0 && r < N && switches[l] == switches[r]) {
				switches[l] = !switches[l];
				switches[r] = !switches[r];
				l--;
				r++;
			}
		}
	}

	// 20개마다 줄바꿈하여 출력
	for (int i = 0; i < N; ++i) {
		std::cout << switches[i];
		if ((i + 1) % 20 == 0 || i == N - 1) {
			std::cout << '\n';
		}
		else {
			std::cout << ' ';
		}
	}

	return 0;
}