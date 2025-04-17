#include <iostream>
#include <cmath>
#define MAX 1001

// 두 개의 문자열이 주어졌을 때, LCS를 구하는 문제
// 예를 들어, ACAYKP와 CAPCAK의 LCS는 ACAK가 된다.
// 참고 : https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence

// str1[0 ~ (str1.length() - 1)]과 str2[0 ~ (str2.length() - 1)]의 길이
// 즉 테이블을 그릴 때 row는 str1(i축), column은 str2(j축)로 생각하여 그리면 됨
int DP[MAX][MAX];	

int main() {
	std::string str1;
	std::string str2;

	std::cin >> str1 >> str2;

	for (int i = 0; i <= str1.length(); i++) {
		for (int j = 0; j <= str2.length(); j++) {
			
			// 둘 중 하나라도 공집합일 때는 LCS가 0
			if (i == 0 || j == 0)
				DP[i][j] = 0;
			
			// 현재 문자가 같다면, 이전까지의 LCS + 1
			else if (str1[i] == str2[j])
				DP[i][j] = DP[i - 1][j - 1] + 1;

			/*
			문자가 다르다면, 두 경우의 LCS 길이 중 더 큰 값을 선택
			
			1. str1[i-1]을 제외한 경우: DP[i-1][j] = str1의 i번째 문자를 제외하고 이전까지의 LCS 길이
			2. str2[j-1]을 제외한 경우: DP[i][j-1] = str2의 j번째 문자를 제외하고 이전까지의 LCS 길이
			
			두 경우 중 더 긴 LCS 길이를 선택하여 DP[i][j]에 저장
			*/
			else
				DP[i][j] = std::max(DP[i - 1][j], DP[i][j - 1]);
		}
	}
	std::cout << DP[str1.length() - 1][str2.length() - 1];

	return 0;
}