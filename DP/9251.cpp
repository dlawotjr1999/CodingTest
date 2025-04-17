#include <iostream>
#include <cmath>
#define MAX 1001

// �� ���� ���ڿ��� �־����� ��, LCS�� ���ϴ� ����
// ���� ���, ACAYKP�� CAPCAK�� LCS�� ACAK�� �ȴ�.
// ���� : https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence

// str1[0 ~ (str1.length() - 1)]�� str2[0 ~ (str2.length() - 1)]�� ����
// �� ���̺��� �׸� �� row�� str1(i��), column�� str2(j��)�� �����Ͽ� �׸��� ��
int DP[MAX][MAX];	

int main() {
	std::string str1;
	std::string str2;

	std::cin >> str1 >> str2;

	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			
			// �� �� �ϳ��� �������� ���� LCS�� 0
			if (i == 0 || j == 0)
				DP[i][j] = 0;
			
			// ���� ���ڰ� ���ٸ�, ���������� LCS + 1
			else if (str1[i] == str2[j])
				DP[i][j] = DP[i - 1][j - 1] + 1;

			/*
			���ڰ� �ٸ��ٸ�, �� ����� LCS ���� �� �� ū ���� ����
			
			1. str1[i-1]�� ������ ���: DP[i-1][j] = str1�� i��° ���ڸ� �����ϰ� ���������� LCS ����
			2. str2[j-1]�� ������ ���: DP[i][j-1] = str2�� j��° ���ڸ� �����ϰ� ���������� LCS ����
			
			�� ��� �� �� �� LCS ���̸� �����Ͽ� DP[i][j]�� ����
			*/
			else
				DP[i][j] = std::max(DP[i - 1][j], DP[i][j - 1]);
		}
	}
	std::cout << DP[str1.length() - 1][str2.length() - 1];

	return 0;
}