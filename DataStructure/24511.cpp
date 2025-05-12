#include <iostream>
#include <vector>
#include <deque>

// queuestack에 원소들을 넣었을 때 그 리턴값을 구하는 문제
// i번 자료구조가 큐라면 A_i = 0, 스택이라면 A_i = 1
// queuestack의 작동은 아래와 같다

// 1. x_0을 입력받는다.
// 2. x_0을 1번 자료구조에 삽입한 뒤 1번 자료구조에서 원소를 pop한다.그때 pop된 원소를 x_1이라 한다
// 3. x_1을 2번 자료구조에 삽입한 뒤 2번 자료구조에서 원소를 pop한다.그때 pop된 원소를 x_2이라 한다
// ...
// 4. x_{N - 1}을 N번 자료구조에 삽입한 뒤 N번 자료구조에서 원소를 pop한다.그때 pop된 원소를 x_N이라 한다
// 5. x_N을 리턴

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> vec(N);
	for (int& elm : vec) {
		std::cin >> elm;
	}

	// stack은 새로운 값이 담기자마자 pop되기 때문에 의미없는 자료구조
	// 즉 queuestack 중 queue만을 고려함
	// 예시에서도 알 수 있듯이 새 원소는 맨 앞에서 삽입되며, 최종적으로 pop되는 원소는 자료구조의 맨 뒤에서 연산이 이루어짐
	// 이러한 이유로 양방향에서 연산이 가능한 queuestack은 deque으로 생각할 수 있음
	std::deque<int> queuestack;
	for (int i = 0; i < N; i++) {
		int elm;
		std::cin >> elm;

		// queuestack 중 stack은 무시(내부 원소 포함)
		if (vec[i] == 0)
			queuestack.push_back(elm);
	}

	int T;
	std::cin >> T;
	for (int i = 0; i < T; i++) {
		int elm;
		std::cin >> elm;

		// queue만을 고려했을 때 새로운 원소가 들어오는 것은 push_front로, 리턴되는 값은 pop_back으로 볼 수 있음
		queuestack.push_front(elm);		
		std::cout << queuestack.back() << " ";
		queuestack.pop_back();
	}

	return 0;
}