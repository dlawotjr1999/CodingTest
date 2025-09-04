#include <iostream>
#include <map>
#include <string>
#include <iomanip>

// ������ �̸����� �־��� ��, �� ������ ��ü �����鿡�� �� %�� �����ϴ� �� ���ϴ� ����

int main() {
	int total = 0;
	std::map<std::string, int> map;

	// EOF�� ���� ������ �Է��� ���� �� ������, ������ �Էµ� �� �����Ƿ� getline�� ���� �Է�
	std::string name;
	while (getline(std::cin, name)) {
		map[name]++;
		total++;
	}

	// �Ҽ��� 4°�ڸ����� �ݿø��Ͽ� ���
	std::cout << std::fixed;
	std::cout.precision(4);
	for (const auto& [name, cnt] : map) {
		// 100.0�� ���� �������ν� �� ��ȯ�� ������
		std::cout << name << " " << (cnt * 100.0 / total) << '\n';
	}

	return 0;
}