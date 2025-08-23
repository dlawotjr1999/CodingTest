#include <bits/stdc++.h>

// �Ʒ� ������ ����
// https://www.acmicpc.net/problem/14891

int score;

// ��Ϲ����� ȸ��(�ֱ�)�� ����ϴ� �Լ�
void rotate(std::string& gear, int cmd) {
	if (cmd == 1) {  
		char temp = gear.back();
		gear.pop_back();
		gear.insert(gear.begin(), temp);
	}
	else {  
		char temp = gear.front();
		gear.erase(gear.begin());
		gear.push_back(temp);
	}
}

int main() {
	std::vector<std::string> gears(4);
	for (int i = 0; i < 4; ++i) {
		std::cin >> gears[i];
	}

	int K; 
	std::cin >> K;

	std::vector<std::pair<int, int>> commands(K);
	for (int i = 0; i < K; ++i) {
		int a, b;
		std::cin >> a >> b;
		commands[i] = { a, b };
	}

	for (auto& [num, cmd] : commands) {
		// �ʱ� ����(� ��Ϲ����� ȸ������ ����)
		int dir[4] = { 0,0,0,0 };
		dir[num - 1] = cmd;

		// ���� ��Ϲ����κ��� ���ʿ� �ִ� ��Ϲ������� ��ȭ ���
		for (int i = num - 1; i > 0; --i) {
			// ���� ��Ϲ����� 9�� ���� ���(6�� �ε���)�� ���ʿ� �ִ� ��Ϲ����� 3�� ���� ���(2�� �ε���)�� ���� �ٸ� ���
			// ���� ��Ϲ����� �ݴ� �������� ȸ����
			if (gears[i][6] != gears[i - 1][2])
				dir[i - 1] = -dir[i];  
			else
				break;              
		}

		// ���� ��Ϲ����κ��� �����ʿ� �ִ� ��Ϲ������� ��ȭ ���
		for (int i = num - 1; i < 3; ++i) {
			// ���� ��Ϲ����� 3�� ���� ���(2�� �ε���)�� �����ʿ� �ִ� ��Ϲ����� 9�� ���� ���(6�� �ε���)�� ���� �ٸ� ���
			// ���� �����ϰ� ���� ��Ϲ����� �ݴ� �������� ȸ��
			if (gears[i][2] != gears[i + 1][6])
				dir[i + 1] = -dir[i];
			else
				break;
		}

		// 4���� ��Ϲ������� ȸ������ ����� �� rotate �Լ��� ���� ���� ����� ���
		// -1�� ��쿡�� �ݽð� ����, 1�� ��쿡�� �ð� �������� ȸ��
		for (int i = 0; i < 4; ++i) {
			if (dir[i] != 0)
				rotate(gears[i], dir[i] == 1 ? 1 : -1);
		}
	}

	// �� ��ϵ��� 12�� ���� ���(0�� �ε���)�� ���� ���� ���
	for (int i = 0; i < 4; ++i) {
		if (gears[i][0] == '1') {
			score += (1 << i);  
		}
	}

	std::cout << score;
	return 0;
}