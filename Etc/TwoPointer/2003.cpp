#include <iostream>
#include <vector>

// �־��� ������ �κ��� M�� ������ ����� ���� ���ϴ� ����

using namespace std;

int main() {
	int N, M;
	int cnt = 0;
	cin >> N >> M;

	vector<int> vec(N);
	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}

	int start = 0;

	// ���� ��ġ�� 0���� N-1���� ���ʴ�� �ű�� �˻�
	while (start < vec.size()) {
		int sum = 0;

		for (int i = start; i < vec.size(); i++) {
			sum += vec[i];

			// ���� M�� ������ cnt ����
			if (sum == M) {
				cnt++;
				break;
			}
		}
		start++;
	}

	cout << cnt;

	return 0;
}