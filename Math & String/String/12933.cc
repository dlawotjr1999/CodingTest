#include <iostream>
#include <vector>

// 오리의 울음소리는 "quack"이며, 올바른 오리의 울음 소리는 울음 소리를 한 번 또는 그 이상 연속해서 내는 것임
// 오리들의 울음소리가 뒤섞여 있는 문자열이 주어질 때, 최소 몇 마리의 오리가 존재하는지 구하는 문제  

int answer;

int main() {
	std::string str;
	std::cin >> str;

	// 문자열은 "quack" 의 다섯 문자들의 조합으로 이루어짐
	// 즉 문자열의 길이가 5의 배수가 아닌 경우 오답
	if (str.size() % 5 != 0) {
		std::cout << -1;
		return 0;
	}

	std::vector<bool> visited(str.size(), false);
	
	while (true) {
		// q,u,a,c,k가 각각 0,1,2,3,4의 순서를 가짐
		// 각 문자의 순서와 시퀀스 번호가 일치하면 OK
		int seq = 0;
		bool found = false;

		// 한 번의 순회에서 "quack"을 만족하는 문자열 탐색(연속하지 않아도 됨)
		for (int i = 0; i < str.length(); ++i) {
			if (visited[i])
				continue;

			// 각 순회마다 q,u,a,c,k를 탐색하고 시퀀스 번호를 할당 및 방문 여부 표기
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

		// 모든 문자들을 탐색하거나 시퀀스를 만족하지 못한 경우 break
		// 위의 다섯 조건식을 모두 만족하면 최소 한 마리의 오리가 존재함 
		if (!found)
			break;
		answer++;
	}

	// 표시되지 않은 경우, 즉 q,u,a,c,k 다섯 글자가 존재하지 않거나 시퀀스를 만족하지 않은 경우에는 오답 
	for (int i = 0; i < visited.size(); ++i) {
		if (!visited[i]) {
			std::cout << -1;
			return 0;
		}
	}
	
	std::cout << answer;
	return 0;
}