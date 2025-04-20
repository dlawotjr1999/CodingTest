#include <iostream>
#include <stack>

// ���� ���� : https://www.acmicpc.net/problem/12789
// �Էµ� ���ڵ鿡 ���� ������ Ȱ���Ͽ� 1,2,3,...,n�� ���� �� �ִ��� ���ϴ� ������ ġȯ ����

int main() {
	int N;
	int cnt = 1;
	std::cin >> N;

	std::stack<int> space;

	while (N--) {
		int elm;
		std::cin >> elm;

		// ���� ������ ��ȣǥ�� ���ڰ� ��ġ�ϸ� ������ �޴� ������ �ٷ� �̵�
		if (elm == cnt)
			cnt++;
		// �׷��� �ʴٸ� ������ ���(����)�� �̵��Ͽ� ���
		else
			space.push(elm);
			
		// ���ÿ��� ���� �� �ִ� �л��� ���� ������ ��� ó���ؾ� �ϹǷ� while���� ���ʿ� �־�� ��
		while (!space.empty() && space.top() == cnt) {
			space.pop();
			cnt++;
		}
	}

	if (space.empty()) {
		std::cout << "Nice";
	}
	else
		std::cout << "Sad";

	return 0;
}