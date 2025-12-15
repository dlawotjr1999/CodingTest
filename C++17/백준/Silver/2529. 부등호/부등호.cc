#include <iostream>
#include <vector>
#include <algorithm>

int k;

std::vector<char> vec;
std::vector<std::string> num;
bool visited[10];

void DFS(int cnt, std::string str) {
	if (cnt == k + 1) {
		num.push_back(str);
		return;
	}

	for (int i = 0; i <= 9; ++i) {
		if (visited[i])
			continue;

		if (cnt > 0) {
			if (vec[cnt - 1] == '<' && str.back() > (i + '0'))
				continue;
			if (vec[cnt - 1] == '>' && str.back() < (i + '0'))
				continue;
		}

		visited[i] = true;
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

	std::cout << max_str << '\n' << min_str;
	return 0;
}