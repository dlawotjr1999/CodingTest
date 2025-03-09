#include <iostream>

//첫째 줄에 코드1 의 수행 횟수를 출력한다.
//둘째 줄에 코드1의 수행 횟수를 다항식으로 나타내었을 때, 최고차항의 차수를 출력한다.단, 다항식으로 나타낼 수 없거나 최고차항의 차수가 3보다 크면 4를 출력한다.

template <typename T>
T MenOfPassion(T* A[], int n) {
	int i = int(n / 2);
	return A[i]; //코드1
}

int main() {
	std::cout << "1" << std::endl;
	std::cout << "0" << std::endl;
}