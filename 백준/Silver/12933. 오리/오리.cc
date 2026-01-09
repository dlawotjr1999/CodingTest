#include <iostream>
#include <vector>

int answer;

int main() {
	std::string str;
	std::cin >> str;

	if (str.size() % 5 != 0) {
		std::cout << -1;
		return 0;
	}

	std::vector<bool> visited(str.size(), false);
	
	while (true) {
		int seq = 0;
		bool found = false;

		for (int i = 0; i < str.length(); ++i) {
			if (visited[i])
				continue;

			if (str[i] == 'q' && seq == 0) {
				seq++;
				visited[i] = true;
			}
			else if (str[i] == 'u' && seq == 1) {
				seq++;
				visited[i] = true;
			}
			else if (str[i] == 'a' && seq == 2) {
				seq++;
				visited[i] = true;
			}
			else if (str[i] == 'c' && seq == 3) {
				seq++;
				visited[i] = true;
			}
			else if (str[i] == 'k' && seq == 4) {
				seq = 0;
				visited[i] = true;
				found = true;
			}
		}

		if (!found)
			break;
		answer++;
	}


	for (int i = 0; i < visited.size(); ++i) {
		if (!visited[i]) {
			std::cout << -1;
			return 0;
		}
	}
	
	std::cout << answer;
	return 0;
}