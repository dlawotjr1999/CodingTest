#include <iostream>
#include <string>
#include <map>

// map�� Ȱ���ϴ� ����
// ���ڿ��� �Է��ϸ� ���ڿ��� �´� ���ڸ�, ���ڸ� �Է��ϸ� �׿� �´� ���ڿ��� ����ؾ� �� 

int N, M;
std::map<std::string, int> map;
std::string ary[100001];

int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		std::string name;
		std::cin >> name;
		map.emplace(name, i);
		ary[i] = name;
	}

	for (int i = 0; i < M; i++) {
		std::string input;
		std::cin >> input;

		// �Է°��� ������ ��� �迭���� key�� �´� value(string)�� ���
		// NOTE : stoi �Լ� -> string�� int������ ��ȯ
		if (std::isdigit(input[0])) {
			std::cout << ary[stoi(input)] << '\n';
		}
		// �ݴ��� ���� �Է°��� string�̹Ƿ� value�� �ش��ϴ� ���� ���
		else {
			std::cout << map.find(input)->second << '\n';
		}
	}
}