#include <bits/stdc++.h>

// 외계인이 기타를 주어진 멜로디를 연주하려고 함
// 높은 음을 낼 때는 현재 프렛을 누른 상태로 높은 음의 프렛을 누르며, 프렛에서 낮은 음을 낼 때는 눌렀던 프렛을 떼면 됨
// 이 때 멜로디를 연주하는데 필요한 최소한의 움직임을 구하는 문제

int answer;

int main() {
	int N, P;
	std::cin >> N >> P;

	// 기타가 6개의 줄로 이루어져 있으므로 7개(1 ~ 6)의 stack으로 이루어진 vector를 선언
	std::vector<std::stack<int>> s(7);

	// 세 가지의 경우를 고려함
	// 1. 현재 줄에서 아무것도 누르지 않은 경우
	// 2. 현재 fret보다 높은 음을 연주할 경우
	// 3. 현재 fret보다 낮은 음을 연주할 경우
	for (int i = 0; i < N; ++i) {
		int string, fret;
		std::cin >> string >> fret;
		
		// 현재 fret보다 더 낮은 음의 fret을 누를 때(3의 경우)
		// 현재 fret을 떼고 움직임 1회 추가
		while (!s[string].empty() && s[string].top() > fret) {
			s[string].pop();
			answer++;
		}

		// 아무것도 누르지 않았을 때 즉, 새로운 줄에서 진행을 할 때(1의 경우)
		// 현재 줄의 fret을 누르고 움직임 1회 추가
		if (s[string].empty()) {
			if (fret > 0) { 
				s[string].push(fret);
				answer++; 
			}
		}

		// 현재 fret보다 더 높은 음의 fret을 누를 때(2의 경우)
		// 그 음의 fret을 누르고 움직임 1회 추가
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