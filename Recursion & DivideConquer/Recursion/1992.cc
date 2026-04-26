#include <bits/stdc++.h>

// 쿼드트리에서, 주어진 영상이 모두 0으로만 되어 있으면 압축 결과는 "0"이 되고, 모두 1로만 되어 있으면 압축 결과는 "1"이 됨
// 만약 0과 1이 섞여 있으면 전체를 한 번에 나타내지를 못하고, 사분면으로 나눈 뒤에 압축함
// 영상의 정보가 주어질 때, 영상을 압축한 결과를 구하는 문제

int N;
char field[64][64];

std::string Partition(int start_y, int start_x, int end_y, int end_x) {
	bool isEqual = true;
	
	// 현재 영상의 정보 검사
	// 현재 영상 정보에서 첫 비트와 다른 필드가 나온 경우, 즉 사분면의 정보가 모두 동일하지 않을 경우를 판별
	for (int i = start_y; i <= end_y; ++i) {
		for (int j = start_x; j <= end_x; ++j) {
			if (field[start_y][start_x] != field[i][j]) {
				isEqual = false;
				break;
			}
		}
		if (!isEqual)
			break;
	}

	// 사분면이 모두 0으로 동일하면 0 반환
	if (isEqual && field[start_y][start_x] == '0')
		return "0";

	// 사분면이 모두 1로 동일하면 1 반환
	else if (isEqual && field[start_y][start_x] == '1')
		return "1";

	// 사분면의 정보들이 동일하지 않으면 다시 사분면들로 분할
	else if (!isEqual) {
		int mid_x = (start_x + end_x) / 2;
		int mid_y = (start_y + end_y) / 2;
		
		// "({1사분면의 정보} {2사분면의 정보} {3사분면의 정보} {4사분면의 정보})"의 구조로 재귀
		return '(' + Partition(start_y, start_x, mid_y, mid_x)
		 + Partition(start_y, mid_x + 1, mid_y, end_x)
		 + Partition(mid_y + 1, start_x, end_y, mid_x)
		 + Partition(mid_y + 1, mid_x + 1, end_y, end_x) + ')';
	}
}

int main() {
	std::cin >> N;
	std::string answer = "";

	for (int i = 0; i < N; ++i) {
		std::string input; std::cin >> input;

		for (int j = 0; j < input.length(); ++j) {
			field[i][j] = input[j];
		}
	}

	// N * N 크기의 영상 압축
	// 범위는 (0,0) ~ (N-1, N-1)
	answer = Partition(0, 0, N - 1, N - 1);

	std::cout << answer;
	return 0;
}