#include <iostream>
#include <algorithm>

// �� ���ڿ� S�� T�� ���� �� �Ʒ� ������� ���� S�� T�� �ٲٰ��� ��
// 1. ���ڿ� �ڿ� A�� �߰���
// 2. ���ڿ� �ڿ� B�� �߰��ϰ� ���ڿ��� ������(reverse)
// �� ��, S�� T�� �ٲ� �� �ִ����� Ȯ���ϴ� ����

// S���� T�� �ٲٴ� ����� ���� ���� ������ ���� �� ����
// �ݴ�� T�� S�� �ٲ� �� �ִ��� Ȯ���ϴ� ����� �����

std::string S, T;
bool isPossible;

// t�� 1��, 2�� ����� ��쿡 �ش��� �� �����Ƿ� if-else if�� �ƴ� if-if�� ����ؾ���
void Solve(std::string& t) {
	// ���� ����� ������� t�� S�� ���ٸ� S�� T�� ������ ������
	if (t == S) {
		isPossible = true;
		return;
	}

	// t�� ���̰� S�� ���̺��� ª������ ����
	if (t.length() < S.length())
		return;
	
	// t�� �� �� ���ڰ� B�� ���, BS'�̹Ƿ� 2�� ������ �ݴ�� ������
	if (t.front() == 'B') {
		std::string temp = t;
		std::reverse(temp.begin(), temp.end());
		temp.pop_back();
		Solve(temp);
	}

	// t�� �� �� ���ڰ� A�� ���, �� S'A�̹Ƿ� 1�� ������ �ݴ�� ������
	if (t.back() == 'A') {
		std::string temp = t;
		temp.pop_back();
		Solve(temp);
	}
}

int main() {
	std::cin >> S >> T;
	Solve(T);

	std::cout << isPossible ? 1 : 0;
	return 0;
}