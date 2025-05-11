#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// ���� ���� ������ ���� ���� ������� �־��� ��, �赵 ���� ���� ����� ���ϴ� ����

int main() {
	int N, M;
	std::unordered_map<std::string, int> map;
	std::vector<std::string> vec;

	std::cin >> N >> M;

	// ���� ���� ����� map�� ����
	for (int i = 0; i < N; i++) {
		std::string n;
		std::cin >> n;
		map.emplace(n, 1);
	}

	// ���� ���� ����� �Է�
	for (int j = 0; j < M; j++) {
		std::string m;
		std::cin >> m;

		// ���� ���� ����� map���� Ž���Ǹ� vector�� ����
		if (map.find(m) != map.end())
			vec.emplace_back(m);
	}

	// ������ ��ġ�� ���� ����
	std::sort(vec.begin(), vec.end());

	std::cout << vec.size() << std::endl;
	for (auto& name : vec)
		std::cout << name << std::endl;
}