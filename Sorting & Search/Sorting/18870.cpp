#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// 정렬 응용 문제
// -10^9 ≤ X_i ≤ 10^9이므로 long long 자료형 사용

int main() {
	int N;
	std::cin >> N;

	std::vector<long long> vec;	
	std::map<long long, long long> map;

	for (int i = 0; i < N; i++) {
		int elm;
		std::cin >> elm;

		vec.push_back(elm);
		map.insert({ vec[i], 0 }); // map에 저장되기 때문에 key에 따라 자동으로 정렬이 이루어짐
	}

	// 정렬된 key에 따라 value 증가(좌표 압축을 위함), 즉 가장 작은 값을 0으로 두는 것으로 시작
	int i = 0;
	for (auto& elm : map) {
		elm.second = i++;
	}

	// 원래 입력된 숫자의 순서에 맞게 출력(vec에는 입력된 순서에 맞게 값이 저장되어 있기 때문)
	 /* NOTE : ector와 map을 동시에 활용하면 원래 입력된 순서를 유지하면서, 특정 기준에 따라 변환된 값을 찾을 수 있음 */
	for (auto& idx : vec) {
		std::cout << map[idx] << " ";
	}

	return 0;
}