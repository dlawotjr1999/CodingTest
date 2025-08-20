#include <bits/stdc++.h>

int answer;

int main() {
	int N, P;
	std::cin >> N >> P;

	std::vector<std::stack<int>> s(7);
	for (int i = 0; i < N; ++i) {
		int string, fret;
		std::cin >> string >> fret;
	
		while (!s[string].empty() && s[string].top() > fret) {
			s[string].pop();
			answer++;
		}

		if (s[string].empty()) {
			if (fret > 0) { 
				s[string].push(fret);
				answer++; 
			}
		}
		else { 
			if (s[string].top() < fret) {
				s[string].push(fret);
				answer++; 
			}
		}
	}

	std::cout << answer;
	return 0;
}