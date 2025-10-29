#include <bits/stdc++.h>

// �� ���Ұ� 1������ N�������� üũ����Ʈ�� ��ġ�� �������� �ϰ� ������, �ϳ��� üũ����Ʈ�� �ǳʶٰ��� ��
// �� ��, üũ����Ʈ �� ���� �ǳʶٰ� �޸� �� �ִ� �ּ� �Ÿ��� ���ϴ� ����
// �� ������ �Ÿ��� Manhattan Distance(|x1-x2| + |y1-y2|)�� �����

int answer = INT_MAX;

int main() {
	int N;
	std::cin >> N;

	std::vector<std::pair<int, int>> vec;
	std::vector<int> dist_vec;

	for (int i = 0; i < N; ++i) {
		int x, y;
		std::cin >> x >> y;
		vec.emplace_back(x, y);
	}

	int dist = 0;

	// ��ü �Ÿ��� ���
	for (int i = 0; i < N - 1; ++i)
		dist += (abs(vec[i].first - vec[i + 1].first) + abs(vec[i].second - vec[i + 1].second));

	// Ư�� ������ �ǳʶ� ���� �Ÿ� ���
	// ���� ��� (i+1)�� ������ �ǳʶپ� i�� �������� (i+2)�� �������� �ٷ� ���� �Ÿ��� �Ʒ��� ����
	// ��ü �Ÿ� - ((i�� �������� (i+1)�� ���������� �Ÿ�) + ((i+1)�� �������� (i+2)�� ���������� �Ÿ�)) + (i�� �������� (i+2)�� ���������� �Ÿ�)
	// �̴� ������ ���ӵ� ������ �Ÿ��� ���� �ǳʶ� ������ �Ÿ��� ��ü�ϱ� ������
	for (int i = 1; i < N - 1; ++i) {
		int removed1 = (abs(vec[i - 1].first - vec[i].first) + abs(vec[i - 1].second - vec[i].second));
		int removed2 = (abs(vec[i].first - vec[i + 1].first) + abs(vec[i].second - vec[i + 1].second));
		int direct = (abs(vec[i - 1].first - vec[i + 1].first) + abs(vec[i - 1].second - vec[i + 1].second));
		
		int temp = dist - (removed1 + removed2) + direct;
		dist_vec.push_back(temp);
	}

	// �� �������� �ǳʶپ� ���ŵ� �Ÿ��� �� ���� ª�� �Ÿ��� ä����
	answer = *std::min_element(dist_vec.begin(), dist_vec.end());
	std::cout << answer;
	return 0;
}
