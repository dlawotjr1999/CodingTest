#include <iostream>
#include <cstring>

// ���ǿ� ��ȸ ����
// https://ko.wikipedia.org/wiki/%EC%99%B8%ED%8C%90%EC%9B%90_%EB%AC%B8%EC%A0%9C

constexpr int MAX = 16;
constexpr int INF = 1e9;

int N;
int full_bit;

int matrix[MAX][MAX];

// ���� ��� ��ȣ�� ���������� �湮 ���¸� �����ϴ� ���̺�
// e.g. DP[2][0b01101] : ���� 2�� ������, { 0,2,3 }�� ���ø� �̹� �湮���� ��, ������ ���ø� ��� �湮�ϰ� 0������ ���ƿ��� �ּ� ���
int DP[MAX][1 << MAX];

int DFS(int cur_node, int cur_bit) {
	// ��� ��带 �湮�� �����̸�, ���� ��忡�� 0������ ���� ��ΰ� ������ �ּ� ��� ��ȯ
	// �Ұ����� ��쿡�� INF ��ȯ
	if (cur_bit == full_bit) {
		if (matrix[cur_node][0] != 0)
			return matrix[cur_node][0];
		return INF;
	}

	// �̹� ���� ���� ������ ��ٷ� ��ȯ�Ͽ� �ߺ��� ����
	int& ret = DP[cur_node][cur_bit];
	if (ret != -1) 
		return ret;

	ret = INF;
	for (int i = 0; i < N; i++) {
		int cost = matrix[cur_node][i];

		// cur_bit�� i�� ��Ʈ�� 1�̰ų�(�� i�� ��带 �湮�߰ų�), cost�� 0�� ��(�� ������ ���� ��)�� �ǳʶ�
		if (cur_bit & (1 << i) || cost == 0)
			continue;

		// �湮�� ��� �� �ּҺ���� ���� ��η� �̵���
		ret = std::min(ret, DFS(i, cur_bit | (1 << i)) + cost);
	}
	return ret;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> matrix[i][j];
		}
	}
	full_bit = (1 << N) - 1;

	memset(DP, -1, sizeof(DP));
	std::cout << DFS(0, 1);

	return 0;
}