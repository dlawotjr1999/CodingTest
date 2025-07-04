#include <iostream>
#include <list>

// �Ʒ� Ŀ�ǵ���� �����ϴ� �����͸� �����ϴ� ����
// L : Ŀ���� �������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
// D : Ŀ���� ���������� �� ĭ �ű� (Ŀ���� ������ �� ���̸� ���õ�)
// B : Ŀ�� ���ʿ� �ִ� ���ڸ� ������ (Ŀ���� ������ �� ���̸� ���õ�)
// P $ : $��� ���ڸ� Ŀ�� ���ʿ� �߰���

int main() {
	std::string input; 
	int N;

	std::cin >> input;
	std::cin >> N;

	// ������� �� ���ھ� �̷���� ���� ����Ʈ�� ����
	std::list<char> input_list(input.begin(), input.end());
	// Ŀ���� ������ ������ �� ��(����Ʈ�� �� ��)�� ��ġ
	auto cursor = input_list.end();

	for (int i = 0; i < N; ++i) {
		char cmd; std::cin >> cmd;
		
		if (cmd == 'L') {
			if (cursor == input_list.begin())
				continue;
			// Ŀ���� ������ �� ĭ �̵�
			cursor--;
		}
		else if (cmd == 'D') {
			if (cursor == input_list.end())
				continue;
			// Ŀ���� �ڷ� �� ĭ �̵�
			cursor++;
		}
		else if (cmd == 'B') {
			// Ŀ���� ó�� ��ġ�� �ƴ� ��쿡�� ���� Ŀ�� ���� ���ڸ� ����
			if (cursor != input_list.begin())
				cursor = input_list.erase(--cursor);
		}
		// ���� Ŀ���� ��ġ�� ���� �ϳ��� ����
		// ���� Ŀ���� ��ġ�� �ִ� ���ڴ� �ڷ� �з���
		else if (cmd == 'P') {
			char c;	std::cin >> c;
			input_list.insert(cursor, c);
		}
	}

	for (char c : input_list) std::cout << c;
	std::cout << "\n";

	return 0;
}