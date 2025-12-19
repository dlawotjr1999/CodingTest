#include <bits/stdc++.h>

// 사람들이 줄 서는 위치를 기록해 놓고, 아침에 기록해 놓은 것과 사람들이 줄을 선 위치가 맞는지 확인하고자 함
// 사람들은 자기보다 큰 사람이 왼쪽에 몇 명 있었는지만을 기억함
// 각 사람들이 기억하는 정보가 주어질 때, 줄을 어떻게 서야 하는지 구하는 문제

// 키가 작은 순서대로 배치하고 있기 때문에 현재 배치하려는 사람보다 키가 큰 사람은 아직 배치되지 않음
// 따라서 현재까지 배치된 모든 사람들은 현재 사람보다 키가 작다는 것을 알 수 있음

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	std::vector<int> answer(N, 0);

	// 먼저 본인 왼쪽에 있는 키가 더 큰 사람의 수를 체크함
	// 왼쪽에서부터 그 인원 수만큼 떨어진 곳의 위치에 배정
	// 만약 그 위치에 누군가가 서 있으면, 오른쪽으로부터 한 칸씩 확인하고 빈 칸에 배정  
	for (int i = 0; i < N; ++i) {
		int cnt = vec[i];
		
		for (int j = 0; j < N; ++j) {
			if (answer[j] == 0) {
				if (cnt == 0) {
					answer[j] = i + 1;
					break;
				}
				cnt--;
			}
		}
	}

	for (int a : answer)
		std::cout << a << ' ';
	return 0;
}