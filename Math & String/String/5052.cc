#include <iostream>
#include <vector>
#include <algorithm>

// ��ȭ��ȣ ����� �ϰ����� �����Ϸ���, �� ��ȣ�� �ٸ� ��ȣ�� ���ξ��� ��찡 ����� ��
// ��ȭ��ȣ�� ��ϵ��� ���� ��ȣ���� �ϰ����� �ִ��� �������� ���ϴ� ����

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;
		std::vector<std::string> nums(n);

		for (int i = 0; i < n; ++i) {
			std::cin >> nums[i];
		}

		// ������ �����ϸ� �ݵ�� ���ξ�� ���ξ ������ ���ڿ��� �����ϰ� ��
		std::sort(nums.begin(), nums.end());
		bool isConsistent = true;

		for (int i = 0; i < n - 1; ++i) {
			// ������ �� ��ȣ���� ����
			// Ư�� ��ȣ(���ξ�)�� ���� ��ȣ�� ù ��° ��ġ�� ��Ȯ�� �����Ѵٸ�, ���� ��ȣ�� ���ξ �����ٴ� �ǹ� 
			// ��ȭ��ȣ�� ��Ͽ� ���ξ� �ִ� ��쿡�� �ϰ����� �������� ����
			if (nums[i + 1].find(nums[i]) == 0) {
				std::cout << "NO\n";
				isConsistent = false;
				break;
			}
		}

		if (isConsistent)
			std::cout << "YES\n";
	}

	return 0;
}