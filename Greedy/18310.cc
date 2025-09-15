#include <iostream>
#include <vector>
#include <algorithm>

// ������ ���� Ư�� ��ġ�� ���� ���׳��� ��ġ�Ϸ��� �ϸ�, ���׳��� ���� ��ġ�ϴ� ������ ��ġ�� �� ����
// �� �� ȿ������ ���� ��� �������� �Ÿ��� ���� �ּҰ� �Ǵ� ��ġ�� ���׳��� ��ġ�Ϸ��� �� ��, �� ��ġ�� ���ϴ� ����

int main() {
	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// ���� ��ġ�� �ε��� ������� ������ �� �� �߰� ������ ������ ��ġ�� ��
	std::sort(vec.begin(), vec.end());

	std::cout << vec[(vec.size() - 1) / 2];
	return 0;
}