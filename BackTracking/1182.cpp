#include <iostream>
#include <vector>

// �κм����� �� ����
// N���� ������ �̷���� ������ ���� ��, ũ�Ⱑ ����� �κм��� �߿��� �� ������ ���Ҹ� �� ���� ���� S�� �Ǵ� ����� ���� ���ϴ� ����

int N, S;
int cnt;

std::vector<int> vec;

void DFS(int depth, int sum) {

	// �������� : N������ Ž���Ͽ��� �� �� ���� S�� ��� ���� ����
	if (depth == N) {
		if (sum == S) {
			cnt++;
		}
		return;
	}

	DFS(depth + 1, sum);				// ���� ���Ҹ� �������� �ʴ� ���
	DFS(depth + 1, sum + vec[depth]);	// ���� ���Ҹ� �����ϴ� ���
}

int main() {
	std::cin >> N >> S;

	for (int i = 0; i < N; i++) {
		int elm; std::cin >> elm;
		vec.push_back(elm);
	}
	
	DFS(0, 0);

	// �������� ���� ���ش�
	if (S == 0)
		cnt--;
	std::cout << cnt;

	return 0;
}