#include <iostream>

// ¼³ÅÁÀ» Á¤È®È÷ NÅ³·Î±×·¥ ¹è´ŞÇØ¾ß ÇÒ ¶§ ÇÊ¿äÇÑ 5kg ºÀÁö¿Í 3kg ºÀÁöÀÇ ÃÖ¼Ò °¹¼ö¸¦ ±¸ÇÏ´Â ¹®Á¦
// ¸¸¾à µÎ ºÀÁö·Î ¸¸µé ¼ö ¾ø´Â ¹«°ÔÀÎ °æ¿ì -1À» ­ˆ·Â
int main() {
	int N;
	int pocketA, pocketB;

	std::cin >> N;

	// 5kg ºÀÁö¸¦ ÃÖ´ëÇÑ È°¿ëÇØ¾ß °¹¼ö¸¦ ÃÖ¼Ò·Î »ç¿ëÇÒ ¼ö ÀÖ´Ù
	pocketA = N / 5;
	while (true) {
		if (pocketA < 0) {
			std::cout << -1;
			return 0;
		}
		// 5kg ºÀÁö·Î ³ª´©°í ³²Àº ¹«°ÔÀÇ ¼³ÅÁÀÌ 3kg ºÀÁöµé·Î ´ãÀ» ¼ö ÀÖ´ÂÁö¸¦ È®ÀÎ
		if ((N - pocketA * 5) % 3 == 0) {
			pocketB = (N - pocketA * 5) / 3;
			break;
		}
		pocketA--;
	}
	std::cout << pocketA + pocketB << std::endl;
}