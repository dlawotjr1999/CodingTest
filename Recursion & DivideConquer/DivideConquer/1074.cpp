#include <iostream>
#include <cmath>

// Z형태로 2차원 배열을 탐색할 때 (r,c)를 몇 번째로 방문하는지 구하는 문제
// 참고 : https://www.acmicpc.net/problem/1074

int N, r, c;
int answer;

void Z_Search(int size, int col, int row) {
	// 타깃 좌표인 경우 출력 후 종료
	if (row == r && col == c) {
		std::cout << answer << '\n';
		return;
	}

	// 배열 탐색
	if ((col <= c && c < col + size) && (row <= r && r < row + size)) {
		Z_Search(size / 2, col, row);				// 1사분면 탐색
		Z_Search(size / 2, col + size / 2, row);	// 2사분면 탐색
		Z_Search(size / 2, col, row + size / 2);	// 3사분면 탐색
		Z_Search(size / 2, col + size / 2, row + size / 2);	// 4사분면 탐색
	}

	// (r,c)가 현재 사분면에 없는 경우 탐색할 필요가 없으므로 size*size만큼 더해줌
	// 그 만큼의 탐색이 이미 진행되었다고 취급할 수 있기 때문 
	else {
		answer += size * size;
	}
}

int main() {
	std::cin >> N >> r >> c;

	// (1 << N) 연산으로 (2^N * 2^N) 크기의 필드 생성
	Z_Search((1 << N), 0, 0);

	return 0;
}