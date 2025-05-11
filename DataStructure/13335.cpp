#include <iostream>
#include <vector>
#include <queue>

// �ٸ� ���� W, �ִ� ���� L, N���� Ʈ�� ���԰� �־��� ��, ��� ���� Ʈ���� ������� �ٸ��� �ǳʴ� �� �ɸ��� �ּ� �ð��� ���ϴ� ����
// �� �ʸ��� Ʈ���� �ٸ� ���� �� ĭ�� �̵��ϸ�, �ٸ� �� Ʈ������ ���� ���� L�� ���� �ʾƾ� ��

std::vector<int> trucks;
std::queue<int> bridge;

int main() {
	int n, w, L;
	std::cin >> n >> w >> L;

	trucks.resize(n);
	for (int& truck : trucks) {
		std::cin >> truck;
	}

	int time = 0;
	int truck_weights = 0;
	int idx = 0;

	// ��� Ʈ���� ����ϰ�, �ٸ� ���� Ʈ���� ���� ������ �ݺ�
	// ���� Ʈ�� ó���� �ٸ� �� Ʈ�� ���� ��� �� ������ ��� ������Ű�� ���� OR ���
	while (idx < n || truck_weights > 0) {
		time++;

		// �ٸ� ���� �ø�(ť�� ����) ĭ�� �ٸ� ����(w)�� ��������
		// �� �տ� �ִ� Ʈ���� �ٸ��� ����� ��
		if (bridge.size() == w) {
			truck_weights -= bridge.front();
			bridge.pop();
		}

		// ���� ��� ���� Ʈ���� �����ְ�,
		// ���� Ʈ���� �÷��� �� �ٸ� �ִ� ����(L)�� ���� ������ �ٸ��� Ʈ�� ����
		if (idx < n && truck_weights + trucks[idx] <= L) {
			bridge.push(trucks[idx]);
			truck_weights += trucks[idx];
			idx++;
		}
		
		// ���� �Ұ� �� �� ĭ(0)�� �־� �ð��� �帣�� ��
		else {
			bridge.push(0);
		}
	}

	std::cout << time;
	return 0;
}