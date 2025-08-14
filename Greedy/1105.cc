#include <iostream>
#include <string>

// 두 수가 주어졌을 때, 두 수 사이에 있는 8이 가장 적게 들어있는 수에 들어있는 8의 갯수를 구하는 문제

int answer;

int main() {
	int L, R;
	std::cin >> L >> R;

	std::string left = std::to_string(L);
	std::string right = std::to_string(R);
	size_t len = std::max(left.length(), right.length());

	// 더 짧은 길이를 가진 수의 앞에 0으로 패딩을 넣어 길이를 맞춤
	if (left.length() < len) {
		left.insert(0, len - left.length(), '0');
	}
	if (right.length() < len) {
		right.insert(0, len - right.length(), '0');
	}
 
	// 두 문자열의 같은 인덱스를 순차 비교하면서 접두사가 완전히 일치하는 구간 중 '8'인 자리만 고려함
	// 만약 L[i] != R[i]가 되는 순간, 이후부터는 그 사이에 8의 갯수가 달라질 수 있으므로 탐색을 종료함
	for (int i = 0; i < len; ++i) {
		// 자릿수가 다른 경우에는 그 이전만큼의 8만이 존재함
		if (left[i] != right[i]) {
			break;
		}
		// 자릿수가 같은 경우에는 그 만큼의 8이 존재함
		if (left[i] == '8' && right[i] == '8')
			answer++;
	}

	std::cout << answer;
	return 0;
}