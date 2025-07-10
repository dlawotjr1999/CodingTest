#include <iostream>
#include <vector>

int answer;

int main() {
	int N, K;
	std::string str;

	std::cin >> N >> K;
	std::cin >> str;

	std::vector<bool> vec(N, false);

	for(int i = 0; i < N; ++i) {
		if (str[i] != 'P')
			continue;
		for (int d = -K; d <= K; ++d) {
			int j = i + d;
			
			if (j < 0 || j >= N)
				continue;
			if (str[j] == 'H' && !vec[j]) {
				vec[j] = true;
				answer++;
				break;
			}
		}
	}

	std::cout << answer;
	return 0;
}