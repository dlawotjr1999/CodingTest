#include <bits/stdc++.h>

// ���� ��û�� ���� ���� �ý����� �Ʒ��� ���� ������ ��, ������û�� ������ �ο����� ���ϴ� ����
// - ������û ��ư�� Ȱ��ȭ�Ǹ�, ������û ��ư�� �����̶� ���� ���� �л��� ����Ͽ� ���� ��
// - �̹� ��⿭�� �� �ִ� ���¿��� �ٽ� ������û ��ư�� ���� ��� ������� �� �ڷ� �з���
// - ��� �� ������û ��ư�� ��Ȱ��ȭ �Ǹ� ����Ͽ��� ���� �տ� �ִ� �л����� �ڵ����� ������û�� �Ϸ�Ǹ�, ���� ���� �ο��� �� �� ��� ������ ������� �����ϰ� ������û�� ������

int main() {
	int K, L;
	std::cin >> K >> L;

	std::map<std::string, int> map;
	for (int i = 0; i < L; ++i) {
		std::string num;
		std::cin >> num;

		// �ߺ��� ������� ���ŵǾ�� �ϱ� ������ value�� i�� �����(value�� ��������� ����)
		map[num] = i;
	}

	std::vector<std::pair<std::string, int>> students(map.begin(), map.end());

	// ������� ���� ����
	std::sort(students.begin(), students.end(), [&](const auto& l, const auto& r) {
		return l.second < r.second;
	});

	// ���� ��û �ο����� ���� �������� ���� �� �����Ƿ� �� �� �ּڰ��� ���ؾ� �� 
	for (int i = 0; i < std::min(K, (int)students.size()); ++i) {
		std::cout << students[i].first << '\n';
	}

	return 0;
}