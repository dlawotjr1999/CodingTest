#include <iostream>
#include <vector>
#include <algorithm>

// 부등호만으로 이루어진 문자열이 주어질 때, 부등호 사이에 0부터 9까지의 서로 다른 숫자들을 넣어서 문자열을 만들고자 함
// 이 때, 부등호 관계를 만족하는 최소, 최대 정수(숫자열)을 구하는 문제

int k;

std::vector<char> vec;
std::vector<std::string> num;
bool visited[10];

void DFS(int cnt, std::string str) {
	// 부등호 관계를 만족하는 (k+1) 길이의 정수가 만들어지면 num 벡터에 저장  
	if (cnt == k + 1) {
		num.push_back(str);
		return;
	}

	for (int i = 0; i <= 9; ++i) {
		if (visited[i])
			continue;

		// 부등호가 존재하는 문자열인 경우
		// 앞선 부등호가 '<'지만 문자열의 맨 뒤 숫자가 현재 숫자보다 큰 경우에는 건너뜀
		// 앞선 부등호가 '>'지만 문자열의 맨 뒤 숫자가 현재 숫자보다 작은 경우에는 건너뜀
		if (cnt > 0) {
			if (vec[cnt - 1] == '<' && str.back() > (i + '0'))
				continue;
			if (vec[cnt - 1] == '>' && str.back() < (i + '0'))
				continue;
		}

		visited[i] = true;

		// 부등화 관계를 만족하는 숫자인 경우 str에 현재 숫자 추가
		DFS(cnt + 1, str + char(i + '0'));
		visited[i] = false;
	}
}

int main() {
	std::cin >> k;
	vec.resize(k);

	for (int i = 0; i < k; ++i)
		std::cin >> vec[i];
	DFS(0, "");

	std::string min_str = *std::min_element(num.cbegin(), num.cend());
	std::string max_str = *std::max_element(num.cbegin(), num.cend());

	// 가장 작은 정수와 가장 큰 정수 출력
	std::cout << max_str << '\n' << min_str;
	return 0;
}