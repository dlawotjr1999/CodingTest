#include <iostream>

// N���� �ڿ����� �̷���� ������ �� ���� S�� E�� �־���
// �� ��, ������ S��° ������ E��°������ ���� �Ӹ���������� ���ϴ� ����

// DP[s][e] : s�� ���ں��� e�� ���ڱ����� �Ӹ���������� ���� 
int arr[2001];
bool DP[2001][2001];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N; std::cin >> N;
    for (int i = 1; i <= N; ++i)
        std::cin >> arr[i];

    // �ϳ��� ���ڷθ� �̷���� ������ �Ӹ����
    for (int i = 1; i <= N; ++i) 
        DP[i][i] = true;

    // �� ���� ���ڷ� �̷���� ������ �Ӹ���� ���� Ȯ��
    for (int i = 1; i < N; ++i) {
        if (arr[i] == arr[i + 1]) 
            DP[i][i + 1] = true;
    }

    // ��� �������� s�� ���ں��� e�� ���ڱ����� �Ӹ�����̶�� (s+1)�� ���ں��� (e-1)�� ���ڱ����� �Ӹ����
    for (int len = 3; len <= N; ++len) {
        for (int i = 1; i + len - 1 <= N; i++) {
            int j = i + len - 1;

            // DP[i + 1][j - 1]�� ���� i�� ���ڿ� j�� ���ڰ� �����ϸ� i�� ���ں��� j�� ���ڱ����� �Ӹ����
            if (arr[i] == arr[j] && DP[i + 1][j - 1]) 
                DP[i][j] = true;
        }
    }

    int M; std::cin >> M;
    while (M--) {
        int s, e; std::cin >> s >> e;
        std::cout << (DP[s][e] ? 1 : 0) << "\n";
    }
}