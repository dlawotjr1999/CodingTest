#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

// ������, �߾Ӱ�, �ֺ�, ���� ���ϱ�
// ������ : N���� ������ ���� N���� ���� ��
// �߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
// �ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��. ���� �� ���� ������ �ֺ� �� �� ��°�� ���� ���� ����Ѵ�.
// ���� : N���� ���� �� �ִ񰪰� �ּڰ��� ����

int main() {
    int N, sum = 0;
    std::cin >> N;

    std::vector<int> vec(N);
    std::unordered_map<int, int> freq;  // �ֺ��� ���ϱ� ���� map

    for (int i = 0; i < N; i++) {
        std::cin >> vec[i];
        sum += vec[i];  // �������� ���ϱ� ����
        freq[vec[i]]++; // �ֺ��� ���ϱ� ���� map�� �̿�. �ߺ� �Է� �� vec[i]�� value�� ������Ŵ 
    }

    std::sort(vec.begin(), vec.end());

    int size = vec.size();

    int mean = std::round(static_cast<double>(sum) / size); // ������
    int center = vec[size / 2];                             // �߾Ӱ�

    // �ֺ� ���ϱ�
    // ������ ���� map�� pair�� �̿��� vector�� ��ȯ
    std::vector<std::pair<int, int>> temp(freq.begin(), freq.end());
    // value, �� �󵵼��� ���� ����, ���� �󵵼��� ���ٸ� �� ���� ���� �տ� ��ġ�ϵ��� ��
    std::sort(temp.begin(), temp.end(), [](auto const& l, auto const& r)
        {
            return l.second != r.second ? l.second > r.second : l.first < r.first;
        });
    int mode = temp[0].first;

    // �� ��°�� ���� ���� �ֺ����� ��
    if (temp.size() > 1 && temp[0].second == temp[1].second)
        mode = temp[1].first;

    int range = vec[size - 1] - vec[0]; // ����

    std::cout << mean << '\n' << center << '\n' << mode << '\n' << range << '\n';

    return 0;
}
