#include <iostream>

// N�� �־����� �� �ĵ��� ���� P(N)�� ���ϴ� ����
// ���� : https://www.acmicpc.net/problem/9461

long long arr[100];

int main() {
	int T;
	std::cin >> T;

	arr[0] = arr[1] = arr[2] = 1;
	arr[3] = arr[4] = 2;

	// ������ ��Ģ�� Ȯ���Ͽ��� ��, i��° �ﰢ���� ���̴� (i-5)��° �ﰢ���� (i-1)��° �ﰢ���� ������ �հ� ���� 
	// �� ��ȭ���� N[i] = N[i - 5] + N[i - 1]
	for (int i = 5; i < 100; i++) {
		arr[i] = arr[i - 5] + arr[i - 1];
	}

	// �ٸ� Ǯ��) �ܼ��� ������ ��Ģ���� �ذ�
	//arr[0] = arr[1] = arr[2] = 1;

	//for (int i = 3; i < 100; i++) {
	//	arr[i] = arr[i - 3] + arr[i - 2];
	//}

	while (T--) {
		int N;
		std::cin >> N;
		std::cout << arr[N - 1] << '\n';
	}

	return 0;
}