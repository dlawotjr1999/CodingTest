#include <iostream>
#include <vector>
#include <algorithm>

// ������ �����ϴ� ������ �� ���� ���� ���� ��, �� ���� �ִ��� ���ϴ� ����
// ������ ��ġ�� ������� ���� �� ������ ���� ��ġ�� �ִ� ���� ���� ���� ����
// ���� ������ ��� ���� �� �� ���� ���ų�, ���� �ʾƾ� ��

int main() {
    int N; std::cin >> N;

    std::vector<int> positives;
    std::vector<int> negatives;
    long long answer = 0;
    int zero_cnt = 0;

    // ����� ������ ����� ����
    // 1�� ���ϴ� �ͺ��� ���ϴ� ���� �� ���踦 �� ũ�� ���� �� �����Ƿ� �ջ����θ� ���
    // ������ ���� ����ϱ� ���� 0�� ���� �ʿ�
    for (int i = 0; i < N; ++i) {
        int v;
        std::cin >> v;
        if (v > 1) 
            positives.push_back(v);
        else if (v == 1) 
            answer++;
        else if (v == 0)
            zero_cnt++;
        else 
            negatives.push_back(v);
    }

    // ����� ������������ �����Ͽ� �� ���� ���� ���ϸ鼭 �ջ�
    // ���� ����� ������ Ȧ�� ���̸� �������� �ִ� ����(���� ���� ���)�� ���ϱ⸸ �ϸ� ��
    std::sort(positives.begin(), positives.end(), std::greater<int>());
    for (size_t i = 0; i + 1 < positives.size(); i += 2) {
        answer += 1LL * positives[i] * positives[i + 1];
    }
    if (positives.size() % 2 == 1) 
        answer += positives.back();

    // ������ ������������ �����Ͽ� �� ���� ���� ���ϸ鼭 �ջ�
    // ���� ������ ������ Ȧ�� ���̸�, 0�� Ȧ�� �� �� �� ������ ��Ҹ� ���ϱ⸸ �ϸ� ��
    std::sort(negatives.begin(), negatives.end());
    for (size_t i = 0; i + 1 < negatives.size(); i += 2) {
        answer += 1LL * negatives[i] * negatives[i + 1];
    }
    if (negatives.size() % 2 == 1) {
        if (zero_cnt == 0) 
            answer += negatives.back();
    }

    std::cout << answer;
    return 0;
}