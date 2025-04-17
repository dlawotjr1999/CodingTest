#include <iostream>
#include <vector>

// N���� � ŰƮ�� �־�����, �� ŰƮ�� Ư�� ���Ը�ŭ �ټս��� ������(�߷� ����).
// ���� 1���� ŰƮ�� ����ؼ� K��ŭ �߷� ���� ��, �ش� ŰƮ�� ���Ը�ŭ �ٽ� ������
// N�� ���� ��� ������ ������ ��, �߷��� �Ϸ�� 500 �̸����� �������� �ʴ� ����� ���� ���ϴ� ����

int N, K;
int cnt;

std::vector<int> vec;
bool visited[9];

void DFS(int day, int weight) {

    // N�ϵ��� �����Ͽ��� ��, �����԰� 500 �̻��� ������ ��쿡 cnt ����
    if (day == N && weight >= 500) {
        cnt++;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (visited[i])
            continue;
        visited[i] = true;

        // ���� �����Կ��� �� ŰƮ�� ��� ���� ���� �����ϴ� �߷��� �Ϸ翡 ������ �߷�(K)�� ����ؼ� Ž�� 
        if (weight + vec[i] - K >= 500)
            DFS(day + 1, weight + vec[i] - K);
        visited[i] = false;
    }
}

int main() {
    std::cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int elm;
        std::cin >> elm;
        vec.push_back(elm);
    }

    DFS(0, 500);
    std::cout << cnt;

    return 0;
}
