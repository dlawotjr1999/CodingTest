#include <iostream>
#include <algorithm>

// �׷� �ܾ�� �ܾ �����ϴ� ��� ���ڿ� ���ؼ�, �� ���ڰ� �����ؼ� ��Ÿ���� ��츦 �ǹ���
// ���� ���, ccazzzzbb�� c, a, z, b�� ��� �����ؼ� ��Ÿ���� ������ �׷� �ܾ�������, aabbbccb�� b�� �������� ��Ÿ���� ������ �׷� �ܾ �ƴ�
// �� ��, �־��� ���ڿ����� �׷� �ܾ������� �Ǻ��ϴ� ����

int cnt;

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; ++i) {
		bool is_group = true;

		// ���ڵ��� ���� ���θ� üũ�ϱ� ���� ���ĺ� �迭 ����
		bool alphabet[26];
		std::fill_n(alphabet, 26, false);

		std::string input;
		std::cin >> input;

		alphabet[input[0] - 'a'] = true;
		for (int j = 1; j < input.size(); ++j) {

			// �Ǻ��ϰ��� �ϴ� ���ĺ��� �̹� üũ�Ǿ� �������� �յ� ���ڰ� �ٸ��� �׷� �ܾ �ƴ�
			// ��, �̹� �����ߴ� ���ĺ��� �ٸ� ���� �׷���� �ڿ� ��Ÿ���� �׷� ���ڰ� �� �� ����
			if (alphabet[input[j] - 'a'] == true && input[j - 1] != input[j]) {
				is_group = false;
			}

			// ���� ��츦 ������ ��쿡�� ���� ���ĺ��� üũ
			alphabet[input[j] - 'a'] = true;
		}

		if (is_group)
			cnt++;
	}

	std::cout << cnt;
	return 0;
}