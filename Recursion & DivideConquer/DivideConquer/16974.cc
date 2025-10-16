#include <iostream>

// ����-L ���Ű� ������ ���� �̷���� �ִٰ� ����
// 1. ����-0 ���Ŵ� ��Ƽ������ �̷���� ����
// 2. ����-L ���Ŵ� �ܹ��Ź�, ���� - (L-1) ����, ��Ƽ, ���� - (L-1)����, �ܹ��Ź����� �̷���� ����
// �� ��, ����-L ������ �Ʒ� X���� �Ծ��� ��, ���� ��Ƽ�� ���� ���ϴ� ����

typedef long long ll;

int N; ll X;

ll burger[51];	// ����-N ������ ũ�� ����
ll patty[51];	// ����-N ������ ��Ƽ�� �� ����

// ����-�������� burger, patty �迭�� Ȱ���Ͽ� ���� ��Ƽ�� ���� ���� 
ll GetAnswer(int n, ll x) {
	// ����-0 ������ ��� : ���� ��쿡�� 1, ���� ���� ��쿡�� 0 
	if (n == 0) {
		if (x == 0)
			return 0;
		else if (x == 1)
			return 1;
	}
	
	// ���� �Ʒ��� ������ �ܹ��� ��
	if (x == 1)
		return 0;
	// ����-n ���Ÿ� (�� + (n-1) ����)���� ���� �Ծ��� ��� : �� �� ���� ������ ����-(n-1) ���� ���� �Ϻ�
	else if (x < 1 + burger[n - 1])
		return GetAnswer(n - 1, x - 1);
	// ����-n ���Ÿ� (�� + (n-1) ����)��ŭ �Ծ��� ��� : patty[n - 1]
	else if (x == 1 + burger[n - 1])
		return patty[n - 1];
	// ����-n ���Ÿ� (�� + (n-1) ���� + ��Ƽ)��ŭ �Ծ��� ��� : patty[n] + 1
	else if (x == 1 + burger[n - 1] + 1)
		return patty[n - 1] + 1;
	// ����-n ���Ÿ� (�� + (n-1) ���� + ��Ƽ (n-1) ����)���� ���� �Ծ��� ��� : patty[n - 1] + �߾� ��Ƽ ���� ������ ����-(n-1) ���� ���� �Ϻ�
	else if (x < 1 + burger[n - 1] + 1 + burger[n - 1])
		return patty[n - 1] + 1 + GetAnswer(n - 1, x - (1 + burger[n - 1] + 1));
	// ����-n ���Ÿ� �� �Ծ��� ��� : patty[n]
	else
		return patty[n];
}

int main() 
	std::cin >> N >> X;

	burger[0] = 1;
	patty[0] = 1;

	// 1���� N���� ������ ũ�� �迭�� ��Ƽ�� �� �迭�� ���
	for (int i = 1; i <= N; ++i)
	{
		burger[i] = 1 + burger[i - 1] + 1 + burger[i - 1] + 1; 
		patty[i] = patty[i - 1] + 1 + patty[i - 1]; 
	}

	std::cout << GetAnswer(N, X);
	return 0;
}