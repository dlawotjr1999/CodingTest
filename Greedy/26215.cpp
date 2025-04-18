#include <iostream>
#include <vector>
#include <algorithm>

// 1�п� �� ���� �� ���� �����ؼ� �� �� ���� ���� ���� 1��ŭ ġ��ų�, �� ���� �����ؼ� �� �� ���� ���� 1��ŭ ġ�� �� �ִ�.
// �� �� ��� �� ���� ���� ���� ġ�� ������ �ɸ��� �ּ� �ð��� ���ϴ� ����
// 24�ð��� �Ѵ� ��쿡�� -1 ���
// idea : ���� ���� ���� ���� �� �� ���� ���� ġ�������� �ּ� �ð��� ���� �� ����

int cnt;

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec;
	for (int i = 0; i < N; i++) {
		int snow; std::cin >> snow;
		vec.push_back(snow);
	}

	// ���� ���� ���� ���� ���� ���ϱ� ���� ���� ����
	std::sort(vec.rbegin(), vec.rend());

	while (vec[0] > 0) {
		
		// ���� �� ä �̻��̰�, �� ���� ���� �׿����� ��쿡 ���� ġ���
		if (N > 1) {
			if (vec[0] > 0)
				vec[0]--;
			if (vec[1] > 0)
				vec[1]--;
		}
		else {
			vec[0]--;
		}
		cnt++;

		// �ٽ� ������ �����Ͽ� ���� ū ���� �պκп� ��� ��ġ��Ų��. �̸� �ݺ��س���
		std::sort(vec.rbegin(), vec.rend());
	}

	if (cnt > 1440)
		cnt = -1;
	std::cout << cnt;

	return 0;
}