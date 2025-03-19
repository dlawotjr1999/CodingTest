#include <iostream>
#include <unordered_map>
#include <algorithm>

int main() {
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		std::unordered_map<std::string, int> map;

		std::cin >> num;

		// ������ �� �ִ� �ǻ��� �������� �����
		for (int j = 0; j < num; j++) {
			std::string s1, s2;
			std::cin >> s1 >> s2;
			map[s2]++;
		}

		int result = 1;

		// �ǻ���� ���� �� �������� ��쵵 �����Ƿ� +1�� �Ͽ� ����� ���� ���Ѵ�
		// ���� ��� (headgear, 2)�� (eyewear, 1)�� ���� �� 
		// (������, headgear1, headgear2)�� (������, eyewear1)�� ����� ���� �ְ�, ������ ������ ���� 3 * 2 = 6�����̴�
		// (������, ������)�� ���� �����ϹǷ� �ᱣ������ 1�� �����Ѵ�

		for (auto& m : map)
			result *= (m.second + 1);
		std::cout << result - 1 << std::endl;
	}
}