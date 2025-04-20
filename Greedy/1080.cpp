#include <iostream>
#define MAX 50

// 0과 1로만 이루어진 행렬 A와 행렬 B가 있을 때, 행렬 A를 행렬 B로 바꾸는데 필요한 연산의 횟수의 최솟값을 구하는 문제
// 행렬을 변환하는 연산은 어떤 3×3크기의 부분 행렬에 있는 모든 원소를 뒤집는 것

int A[MAX][MAX];
int B[MAX][MAX];

int cnt;

// 3 x 3 크기만큼 행렬을 뒤집음
void Reverse(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (A[i][j] == 1)
				A[i][j] = 0;
			else
				A[i][j] = 1;
		}
	}
}

int main() {
	bool flag = true;

	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++) {
		std::string row;
		std::cin >> row;

		for (int j = 0; j < M; j++) {
			A[i][j] = row[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		std::string row;
		std::cin >> row;

		for (int j = 0; j < M; j++) {
			B[i][j] = row[j] - '0';
		}
	}

	// 한 원소에서 3 x 3 행렬을 뒤집는 것이기 때문에 전체 행렬의 인덱스를 고려하여 (N - 2)와 (M - 2)만큼 확인하여 연산을 진행함
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (A[i][j] != B[i][j]) {
				Reverse(i, j);
				cnt++;
			}
		}
	}

	// 연산 후 하나라도 다른 원소가 있으면 A는 B로 변환될 수 없음
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (A[i][j] != B[i][j]) {
				flag = false;
				break;
			}
		}
	}

	if (flag)
		std::cout << cnt;
	else
		std::cout << -1;
	
	return 0;
}