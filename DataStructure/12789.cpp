#include <iostream>
#include <stack>

// 문제 참고 : https://www.acmicpc.net/problem/12789
// 입력된 숫자들에 대해 스택을 활용하여 1,2,3,...,n을 만들 수 있는지 구하는 문제로 치환 가능

int main() {
	int N;
	int cnt = 1;
	std::cin >> N;

	std::stack<int> space;

	while (N--) {
		int elm;
		std::cin >> elm;

		// 현재 순서와 번호표의 숫자가 일치하면 간식을 받는 곳으로 바로 이동
		if (elm == cnt)
			cnt++;
		// 그렇지 않다면 일자형 통로(스택)로 이동하여 대기
		else
			space.push(elm);
			
		// 스택에서 꺼낼 수 있는 학생이 생길 때마다 즉시 처리해야 하므로 while문이 안쪽에 있어야 함
		while (!space.empty() && space.top() == cnt) {
			space.pop();
			cnt++;
		}
	}

	if (space.empty()) {
		std::cout << "Nice";
	}
	else
		std::cout << "Sad";

	return 0;
}