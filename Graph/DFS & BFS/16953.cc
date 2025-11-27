#include <iostream>
#include <climits>
#include <queue>

// 정수 A를 B로 만들기 위해 가능한 연산은 아래와 같음
// 2를 곱하거나, 1을 수의 가장 오른쪽에 추가함
// 이 때, A를 B로 바꾸는데 필요한 연산의 최솟값의 1을 더한 값을 구하는 문제

int BFS(int a, int b) {
	// (연산 결과값, 연산 횟수) 순서쌍을 저장하는 queue를 사용
	// 일반적으로는 dist 배열을 사용하는 것이 권장됨
	std::queue<std::pair<long long, int>> q;
	q.emplace(a, 0);

	while (!q.empty()) {
		auto [cur_num, op_num] = q.front();
		q.pop();

		// a -> b가 가능하면 (연산 횟수 + 1)를 반환
		if (cur_num == b)
			return op_num + 1;
		else if (cur_num > INT_MAX)
			continue;

		// 가장 오른쪽에 1을 추가하는 것은 원래 수에 10을 곱하고 1을 더하는 것과 동일
		// 각 연산으로 만들어진 결과값이 INT_MAX 이내인 경우에만 이후 연산 진행
		else {
			long long mul2 = cur_num * 2;
			long long add1 = cur_num * 10 + 1;

			if (mul2 < INT_MAX)
				q.emplace(mul2, op_num + 1);
			if (add1 < INT_MAX)
				q.emplace(add1, op_num + 1);
		}
	}

	// 만들 수 없는 경우에는 -1 반환
	return -1;
}

int main() {
	int A, B;
	std::cin >> A >> B;

	std::cout << BFS(A, B);
	return 0;
}