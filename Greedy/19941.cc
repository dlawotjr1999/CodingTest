#include <iostream>
#include <vector>

// �� �ٿ� ��P��(���)�� ��H��(�ܹ���)�� �־�����, �� ����� �Ÿ� K �̳��� �ܹ��Ÿ� �ִ� �� �� ���� �� ����
// �� ��, �ִ� �� ���� �ܹ��Ÿ� ���� �� �ִ����� ���ϴ� ����
// ���� ���� ������� Ž���ϸ� ���� �������� ���� ���� ����� �ܹ��Ÿ� �Ҵ��ϸ� ������ �����

int answer;

int main() {
	int N, K;
	std::string str;

	std::cin >> N >> K;
	std::cin >> str;

	// false : �ܹ��Ÿ� ���� ����. �� �ܹ��Ű� ���� ������ �ǹ���
	std::vector<bool> vec(N, false);

	for (int i = 0; i < N; ++i) {
		// ����� ��쿡�� �����
		if (str[i] != 'P')
			continue;

		// ���� ������ Ž�� ����
		for (int d = -K; d <= K; ++d) {
			int j = i + d;

			// ������ ����� continue
			if (j < 0 || j >= N)
				continue;
			// ���� ���� �ܹ��Ű� �ְ�, �ܹ��Ű� �����ִٸ� ���� �� ���� 
			if (str[j] == 'H' && !vec[j]) {
				vec[j] = true;
				answer++;
				break;
			}
		}
	}

	std::cout << answer;
	return 0;
}