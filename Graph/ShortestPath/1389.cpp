#include <iostream>
#include <vector>

// 케빈 베이컨의 수가 가장 작은 사람을 구하는 문제
// 케빈 베이컨 게임 : 임의의 두 사람이 최소 몇 단계 안에 이어질 수 있는지 구하는 문제
// 참고 : https://www.acmicpc.net/problem/1389

constexpr int MAX = 101;
constexpr int INF = 1e9;

int N, M;

std::vector<std::vector<int>> friends;

void FloydWarshall() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (friends[i][j] > friends[i][k] + friends[k][j]) {
					friends[i][j] = friends[i][k] + friends[k][j];
				}
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	std::cin >> N >> M;
	
	friends.resize(N + 1, std::vector<int>(N + 1, INF));
	for (int i = 1; i <= N; i++)
		friends[i][i] = 0;

	for (int i = 0; i < M; i++) {
		int A, B;
		std::cin >> A >> B;
		friends[A][B] = friends[B][A] = 1;
	}
	
	// Floyd-Warhsall 알고리즘 수행 후 배열에는 각 사람들까지 연결되는 관계의 비용이 저장됨
	FloydWarshall();

	int min_cnt = INF;
	int min_person = -1;

	// 가장 작은 케빈 베이컨 수를 가진 사람을 탐색
	for (int i = 1; i <= N; i++) {
		int temp = 0;

		for (int j = 1; j <= N; j++) {
			temp = temp += friends[i][j];
		}
		if (min_cnt > temp) {
			min_cnt = temp;
			min_person = i;
		}
	}

	std::cout << min_person;
	return 0;
}