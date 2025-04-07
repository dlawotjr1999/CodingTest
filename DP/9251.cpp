//#include <iostream>
//#include <cmath>
//#define MAX 1001
//
//int DP[MAX][MAX];
//
//int main() {
//	std::string str1;
//	std::string str2;
//
//	std::cin >> str1 >> str2;
//
//	for (int i = 1; i <= str1.length(); i++) {
//		for (int j = 1; j <= str2.length(); j++) {
//			if (i == 0 || j == 0)
//				DP[i][j] = 0;
//			else if (str1[i] == str2[j])
//				DP[i][j] = DP[i - 1][j - 1] + 1;
//			else
//				DP[i][j] = std::max(DP[i - 1][j], DP[i][j - 1]);
//		}
//	}
//	std::cout << DP[str1.length() - 1][str2.length() - 1];
//
//	return 0;
//}