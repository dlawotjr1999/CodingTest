#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

// 1. ���� ������ �ܾ��ϼ��� �տ� ��ġ�Ѵ�.
// 2. �ش� �ܾ��� ���̰� ����� �տ� ��ġ�Ѵ�.
// 3. ���ĺ� ���� ������ �տ� �ִ� �ܾ��ϼ��� �տ� ��ġ�Ѵ�
// �� �� ������ ��ġ ������ �°� �Է°����� �����ϴ� ����

int main() {
	int N, M;
	std::unordered_map<std::string, int> map;
	
	std::cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		std::string word;
		std::cin >> word;
		map[word]++;
	}

	std::vector<std::pair<std::string, int>> vec(map.begin(), map.end());
	std::sort(vec.begin(), vec.end(), [&](const auto& left, const auto& right) {
		// 1�� ����
		if (left.second != right.second)
			return left.second > right.second;
		// 2�� ����
		if (left.first.size() != right.first.size())
			return left.first.size() > right.first.size();
		// 3�� ����
		return left.first < right.first;
	});

	// M �̻��� ���̸� ���� ���ڿ��� ���
	for (const auto& entry : vec) {
		if (entry.first.size() >= M) {
			std::cout << entry.first << '\n';
		}
	}
	
	return 0;
}