#include <iostream>
#include <vector>
#include <algorithm>

// N���� ����Ʈ�� ������, �� ����Ʈ�� ���� ��ġ�� ����ġ �ο�
// M���� ������ ������ ����Ͽ� ����Ʈ�� �Ϸ��� �� ����
// ����Ʈ�� �Ϸ��� ������, �ش� ����Ʈ�� ����ġ ���� ���� Ȱ��ȭ�� ������ ���濡 ����ġ ����
// �� �� ȹ���� �� �ִ� �ִ� ����ġ�� ���ϴ� ����
// idea : ����ġ ������ ���� ������� �Ϸ��ϸ� �ִ��� ���� �� ����

std::vector<long long> stones;
long long xp;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	long long n, k;
	std::cin >> n >> k;

	stones.resize(n);
	for (long long& stone : stones) {
		std::cin >> stone;
	}

	// ����ġ ������� �������� ����
	std::sort(stones.begin(), stones.end());

	/*
	���÷� n = 6, k = 3�϶�

	100; 200 + 300 + 400 + 500 + 600
	200; 300 + 400 + 500 + 600
	300; 400 + 500 + 600
	400;
	500;
	600;

	���� ���� ������� ������ ���Ѿ� �ִ��� ���� �� ����
	�� (1 * 200) + (2 * 300) + (3 * 400) + (3 * 500) + (3 * 600) = 5300�� �ִ��̹Ƿ�
	s(i) = min(i, k) * stones[i]�� ������ �� �ִ� 
	*/
	for (long long i = 1; i < stones.size(); i++) {
		long long temp = stones[i] * std::min(i, k);
		xp += temp;
	}

	std::cout << xp;

	return 0;
}