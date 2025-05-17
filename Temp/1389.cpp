#include <iostream>
#include <vector>

// �ɺ� �������� ���� ���� ���� ����� ���ϴ� ����
// �ɺ� ������ ���� : ������ �� ����� �ּ� �� �ܰ� �ȿ� �̾��� �� �ִ��� ���ϴ� ����
// ���� : https://www.acmicpc.net/problem/1389

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
	
	// Floyd-Warhsall �˰��� ���� �� �迭���� �� �������� ����Ǵ� ������ ����� �����
	FloydWarshall();

	int min_cnt = INF;
	int min_person = -1;

	// ���� ���� �ɺ� ������ ���� ���� ����� Ž��
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