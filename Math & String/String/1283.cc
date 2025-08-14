#include <bits/stdc++.h>

// �� �ɼǿ� ����Ű�� �ǹ��ϴ� ��ǥ ���ĺ��� �����ϱ�� ���� ��, ����Ű�� �����ϴ� ���� �Ʒ��� ������ ����
// 1. ���� �ϳ��� �ɼǿ� ���� ���ʿ������� ������ ������ �ܾ��� ù ���ڰ� �̹� ����Ű�� �����Ǿ����� ���캸��, ���� ����Ű�� ���� ������ �� �Ǿ��ִٸ� �� ���ĺ��� ����Ű�� ������
// 2. ���� ��� �ܾ��� ù ���ڰ� �̹� ������ �Ǿ��ִٸ� ���ʿ������� ���ʴ�� ���ĺ��� ���鼭 ����Ű�� ���� �� �� ���� �ִٸ� ����Ű�� ������
// 3. ��� �͵� ����Ű�� ������ �� ���ٸ� �׳� ���θ� ��ҹ��ڸ� ����ġ ����
// 4. ���� ��Ģ�� ù ��° �ɼǺ��� N��° �ɼǱ��� ���ʴ�� ������
// �ܾ���� �־��� ��, �� ��Ģ�� ���� ����Ű�� ������ ���ĺ� �¿쿡 [] ��ȣ�� ������ ǥ���� �� ����ϴ� ����

// Note : ���� ��ü�� �Ű��� ���� �ͺ���, �� ���ڰ� ��ġ�� �ε����� Ȱ���ϴ� ���� �� ȿ������

bool alphabet[26];

int main() {
	int N;
	std::cin >> N;

	std::vector<std::string> commands(N);

	// ���� ���ڿ��� �Է¹ޱ� ���� std::cin.ignore() ���
	std::cin.ignore();
	for (int i = 0; i < N; ++i) {
		std::getline(std::cin, commands[i]);
	}

	for (int i = 0; i < N; ++i) {
		std::string& command = commands[i];
		// ���Ϳ��� command�� �� �ܾ��� ���� �ε����� ����
		std::vector<int> idx_vec;

		// command�� ���� ���ڿ��� �ƴ� ��쿡�� ù �ܾ��� �ε����� 0�� �߰���
		if (!command.empty())
			idx_vec.push_back(0);
		for (int i = 0; i < command.size(); ++i) {
			// command�� ����� ���� �ʴ� ������ ������ �ִ� ��ġ�� ã�Ƽ� �� ���� �ε����� �߰���
			if (command[i] == ' ' && i + 1 < command.size())
				idx_vec.push_back(i + 1);
		}
		bool is_checked = false;

		// ���� �� �ܾ��� ù ���ڰ� ����Ű�� �����Ǿ� �ִ��� Ȯ��
		for (int idx : idx_vec) {
			// ��ҹ��ڸ� �������� �ʱ� ���� tolower ���
			char lower_c = tolower(command[idx]);

			if (!alphabet[lower_c - 'a']) {
				command.insert(idx, "[");
				// '[' �������� ���� �ε��� ��ȭ�� ���� idx + 2 ��ġ�� ']'�� ����
				command.insert(idx + 2, "]");
				alphabet[lower_c - 'a'] = true;
				// ����Ű�� �����Ǿ����� ��Ÿ���� �÷��׸� true�� ����
				is_checked = true;
				break;
			}
		}

		// ���� ����Ű�� �������� �ʾҴٸ�, ���ʿ������� ���ʴ�� ���ĺ��� ���鼭 ����Ű�� �������� ���� ���ڸ� ã�Ƽ� ������
		if (!is_checked) {
			for (int j = 0; j < command.size(); ++j) {
				if (!isalpha(command[j]))
					continue;
				char lower_c = tolower(command[j]);

				if (!alphabet[lower_c - 'a']) {
					command.insert(j, "[");
					command.insert(j + 2, "]");
					alphabet[lower_c - 'a'] = true;
					break;
				}
			}
		}
	}

	for (const std::string& command : commands) {
		std::cout << command << '\n';
	}

	return 0;
}