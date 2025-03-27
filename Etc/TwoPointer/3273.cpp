	#include <iostream>
	#include <vector>
	#include <algorithm>

	// �־��� ���� �� �� ������ �հ�, �Էµ� num�� ��ġ�ϴ� ������ ���ϴ� ����
	// �� �����͸� �̿��Ͽ� ����
	int main() {
		int n;
		int num;
		int cnt = 0;
		std::cin >> n;

		std::vector<int> vec(n);
		for (int i = 0; i < vec.size(); i++) {
			std::cin >> vec[i];
		}
		std::cin >> num;

		std::sort(vec.begin(), vec.end());

		int left = 0, right = n - 1;
		while (left < right) {
			if (vec[left] + vec[right] == num) {
				cnt++;
				left++;
				right--;
			}
			else if (vec[left] + vec[right] > num) {
				right--;
			}
			else {
				left++;
			}
		}
		std::cout << cnt << std::endl;

		return 0;
	}