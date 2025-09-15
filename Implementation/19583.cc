#include <bits/stdc++.h>
#include <unordered_set>

// ������ȸ ���� �ο��� Ȯ���Ͽ� �� �ο����� ���ϴ� ����
// �⼮�δ� �Ʒ��� ���� ��Ģ���� ������
// 1. ������ȸ ������ ä�� �αװ� �����ϸ� üũ. �������ڸ��� ä�� �α׸� ���ܵ� �� �ð� �������� ������
// 2. ������ȸ�� ������ ��Ʈ������ ������ ä�� �α׸� ���� ���� Ȯ�� ���� Ȯ��. ��Ʈ������ �����ڸ���  ä�� �α׸� ���ܵ� ������ Ȯ�ε� ������ ������

int answer;

// �ð��� HH:MM ���·� �Է��� �Ǳ� ������ HH�� MM�� �߷��� �� ������ ��ȯ�Ͽ� ��ȯ
inline int time_to_int(const std::string& str) {
	int hour = std::stoi(str.substr(0, 2));
	int minute = std::stoi(str.substr(3, 2));

	return (hour * 60) + minute;
}

int main() {
	// ������ȸ ���۽ð�, ����ð�, ��Ʈ���� ����ð� �Է�
	int time_arr[3];

	for (int i = 0; i < 3; ++i) {
		std::string input; // S, E, Q
		std::cin >> input;
		
		time_arr[i] = time_to_int(input);
	}

	// early ���� : ������ȸ�� ������ ������ ����� ä�� �α׸� ����
	// counted ���� : ������ȸ�� ������ ���� ����� ä�� �α׸� ����
	std::unordered_set<std::string> early;
	std::unordered_set<std::string> counted;

	std::string time, name;
	while (std::cin >> time >> name) {
		int t = time_to_int(time);

		// ������ȸ ���� �� ä�� �αװ� Ȯ�εǸ� early ���տ� �߰�
		if (t <= time_arr[0]) { 
			early.insert(name);
		}

		// ���� ��ȸ�� ����Ǵ� ���� ä�� �αװ� Ȯ�� �Ǵ� ���
		// ���� �� ä�� �αװ� ������ ��, ��ȸ�� ����Ǵ� ���� �� �αװ� �����ϸ� �⼮���� ������ 
		else if (time_arr[1] <= t && t <= time_arr[2]) { 
			if (early.find(name) != early.end() && counted.insert(name).second) {
				answer++;
			}
		}
	}

	std::cout << answer;
	return 0;
}