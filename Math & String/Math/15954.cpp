#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

// Ư���� ���� �������� ��ġ�ϰ��� �ϴµ�, �������� ��ġ�ϴ� ��Ģ�� �Ʒ��� ����
// 1. ���� ����� ������ ������ ��ġ�ϵ��� ���� �ٸ� N���� ������ ������ �� ���� �Ϸķ� ��ġ
// 2. �� ��, ��ȣ�ϴ� ����� ���� ǥ�������� �ּҰ� �Ǵ�, K�� �̻��� ���ӵ� ��ġ�� �ִ� �������� �����Ͽ� �׵��� ���� ���� ��ġ
// �� ��, ���� ������� �������� �������� ��, ���õ� �������� ��ȣ�ϴ� ����� ���� ǥ�������� ���ؾ� ��
// ��, ���� K�� 3�� ��� 3, 4, 5, ... N���� ��ġ�� �������� ��� ǥ�������� ���ؾ� ��

std::vector<int> vec;

int main() {
	int N, K;
	std::cin >> N >> K;

	vec.resize(N);
	for (int i = 0; i < N; i++) {
		std::cin >> vec[i];
	}

	// ǥ�������� �ּڰ��� �����ϱ� ���� ���� ǥ�������� max_value(double)�� ����
	double min_stddev = std::numeric_limits<double>::max();

	//	���� ���ǿ� ���� �ּҰ� �Ǵ� ǥ�������� �Ʒ��� ��츦 ��� ����ؾ� ��(e.g. K = 3�� ���; 0-based)
	// 3 : (0, 1, 2), (1, 2, 3), (2, 3, 4), ... (N-3, N-2, N-1)
	// 4 : (0, 1, 2, 3), (1, 2, 3, 4), (2, 3, 4, 5), ... (N-4, N-3, N-2, N-1)
	// 5 : (0, 1, 2, 3, 4), (1, 2, 3, 4, 5), (2, 3, 4, 5, 6), ... (N-5, N-4, N-3, N-2, N-1)
	// ...
	// N : (0, 1, 2, ... N-1)

	// i : K �̻� N ������ ������ ����ϴ� index 
	for (int i = K; i <= N; i++) {
		// j : i���� �̷���� �׷��� �������� ���ϴ� index
		for (int j = 0; j <= N - i; j++) {  
			double sum = 0;
			
			// k : ���� index(j)�κ��� i���� �̷���� �׷��� ���ҵ��� ���ϴ� index
			for (int k = j; k < j + i; k++) {
				sum += vec[k];
			}
			double avg = sum / i;

			double variance = 0;
			for (int k = j; k < j + i; k++) {
				// �л��� (���� �� - ���)�� ����
				variance += (vec[k] - avg) * (vec[k] - avg);
			}
			variance /= i;

			double stddev = std::sqrt(variance);

			if (stddev < min_stddev)
				min_stddev = stddev;
		}
	}

	// �Ҽ��� 11�ڸ����� ���
	std::cout.precision(11);
	std::cout << std::fixed << min_stddev;

	return 0;
}
