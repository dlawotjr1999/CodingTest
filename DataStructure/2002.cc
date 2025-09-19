#include <bits/stdc++.h>

// 차량들이 순서대로 터널에 진입하며, 출구에서는 터널에서 나오는 차들의 순서를 확인함
// 나오는 차들의 순서가 들어간 순서와 다르다면 차들이 추월을 했을 것이라고 여겨짐
// 이 때, 추월한 것으로 여겨지는 차가 몇 대인지 구하는 문제

int answer;

int main() {
	int N;
	std::cin >> N;

	std::map<std::string, int> map;
	std::vector<std::string> vec(N);

	// 차량의 번호판을 key로, 진입한 순서를 value로 하여 map에 저장 
	for (int i = 0; i < N; ++i) {
		std::string str;
		std::cin >> str;
		map[str] = i;
	}

	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
	}

	// 나오는 차량들을 처음부터 확인하며, 현재 차량의 index가 뒤에 나오는 차량의 원래 index보다 하나라도 크다면 추월한 것
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (map[vec[i]] > map[vec[j]]) {
				answer++;
				break;
			}
		}
	}

	std::cout << answer;
	return 0;
}