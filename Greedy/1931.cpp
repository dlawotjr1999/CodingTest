#include <iostream>
#include <vector>
#include <algorithm>

// �� ���� ȸ�ǽǿ��� ������ �� �ִ� ȸ�ǵ��� �ִ� ������ ���ϴ� ���� 
// �� ȸ�Ǵ� ��ĥ �� ����

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec;
	for (int i = 0; i < N; i++) {
		int start, end;
		std::cin >> start >> end;
		vec.emplace_back(start, end);
	}

	// �� ȸ���� ���� �ð��� ������ �ð��� ��� ����Ͽ� ���� ����
	// ���� �ð��� ���� ��� ���� �ð��� �� ���� ȸ�Ǹ� �����Ͽ� ����
	std::sort(vec.begin(), vec.end(), [&](const auto& a, const auto& b) {
		if (a.second == b.second) 
			return a.first < b.first;
		return a.second < b.second;
	});

	int result = 1;
	int end_time = vec[0].second;

	// ù ȸ�ǰ� ������ ���� ȸ���� ���� �ð��� ù ȸ���� ���� �ð����� Ŭ ��쿡�� ȸ�� ���� ����
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i].first >= end_time) {
			result++;
			end_time = vec[i].second;
		}
	}

	std::cout << result;
	return 0;
}
