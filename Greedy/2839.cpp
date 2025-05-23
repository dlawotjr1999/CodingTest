#include <iostream>

// 설탕을 정확히 N킬로그램 배달해야 할 때 필요한 5kg 봉지와 3kg 봉지의 최소 갯수를 구하는 문제
// 만약 두 봉지로 만들 수 없는 무게인 경우 -1을 춫력
int main() {
	int N;
	int pocketA, pocketB;

	std::cin >> N;

	// 5kg 봉지를 최대한 활용해야 갯수를 최소로 사용할 수 있다
	pocketA = N / 5;
	while (true) {
		if (pocketA < 0) {
			std::cout << -1;
			return 0;
		}
		// 5kg 봉지로 나누고 남은 무게의 설탕이 3kg 봉지들로 담을 수 있는지를 확인
		if ((N - pocketA * 5) % 3 == 0) {
			pocketB = (N - pocketA * 5) / 3;
			break;
		}
		pocketA--;
	}
	std::cout << pocketA + pocketB << std::endl;
}