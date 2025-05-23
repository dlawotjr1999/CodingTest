#include <iostream>
#include <algorithm>

// 문제
// 오늘도 서준이는 점근적 표기 수업 조교를 하고 있다.아빠가 수업한 내용을 학생들이 잘 이해했는지 문제를 통해서 확인해보자.
// 알고리즘의 소요 시간을 나타내는 O - 표기법(빅 - 오)을 다음과 같이 정의하자.
// O(g(n)) = { f(n) | 모든 n ≥ n0에 대하여 f(n) ≤ c × g(n)인 양의 상수 c와 n0가 존재한다 }
// 이 정의는 실제 O - 표기법과 다를 수 있다.
// 함수 f(n) = a1n + a0, 양의 정수 c, n0가 주어질 경우 O(n) 정의를 만족하는지 알아보자.

// 출력
// f(n), c, n0가 O(n) 정의를 만족하면 1, 아니면 0을 출력한다.

int main() {
	int a1, a0, c, n0;
	bool isAccepted = false;

	std::cin >> a1 >> a0;
	std::cin >> c;
	std::cin >> n0;

	// 중요한 것은 a0가 음수일 때도 생각해야한다는 것이다.
	// 따라서 f(n) <= g(n)과 추가적으로 a1 <= c도 고려해야한다.그러면 a0 음수이든 말든 조건을 보장해주기 때문이다.
	int f = a1 * n0 + a0;
	int g = c * n0;
	if (f <= g && a1 <= c) {
		isAccepted = true;
	}

	std::cout << isAccepted;
}