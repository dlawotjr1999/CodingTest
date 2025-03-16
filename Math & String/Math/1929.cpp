#include <iostream>
#define MAX 1000000

int arr[MAX + 1]{ 0, };

// 에라토스테네스의 체를 활용한 소수 판별 문제
// 시간 복잡도 : O(n log(log n))

int main() {

	int start, end;
	std::cin >> start >> end;

	for (int i = 2; i <= end; i++) {
		arr[i] = i;
	}

	// 모든 합성수는 √N 이하의 약수를 가지는 것을 이용
	// 즉, √N까지만 검사하면 나머지는 자동으로 처리됨
	for (int i = 2; i * i <= end; i++) {
		if (arr[i] == 0) continue;
		
		// 각 수의 배수들을 제거
		// i의 배수들은 2*i, 3*i, 4*i, ... 이므로 제거해야 함
		for (int j = i * i; j <= end; j += i) {
			arr[j] = 0;
		}
	}

	for (int i = start; i <= end; i++) {
		if (arr[i] != 0) {
			std::cout << arr[i] << "\n";
		}
	}
}