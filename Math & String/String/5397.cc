#include <bits/stdc++.h>

// 키로거는 사용자가 키보드를 누른 명령을 모두 기록하며, 비밀번호가 입력될 때 화살표나 백스페이스를 입력해도 정확한 비밀번호를 알아낼 수 있음
// 백스페이스를 입력했다면, '-'가 주어지며, 커서의 바로 앞에 글자가 존재한다면 그 글자를 지움
// 화살표의 입력은 '<'와 '>'로 주어지며, 커서의 위치를 움직일 수 있을 때 왼쪽 또는 오른쪽으로 1만큼 움직임
// 비밀번호 창에서 입력한 키가 주어졌을 때, 입력된 비밀번호를 알아내는 문제

int main() {
	int T; std::cin >> T;

	while (T--) {
		std::string input; std::cin >> input;
		
		// 문자열이 최대 1,000,000자일 수 있기 때문에 list를 활용하여 연산 진행
		// 위치를 알고 있을 때, 삽입/삭제 모두 O(1)의 시간 복잡도를 가지기 때문에 효율적임(메모리 측면에서는 아님)
		// 이를 위하여 위치를 기록하는 iterator 이용
		std::list<char> str;
		auto itr = str.begin();

		// 입력된 문자열로 비밀번호 계산
		for (char c : input) {
			
			// c가 왼쪽 화살표인 경우
			// itr가 리스트의 시작점이 아닌 경우에 왼쪽으로 이동
			if (c == '<') {
				if (itr != str.begin()) --itr;
			}

			// c가 오른쪽 화살표인 경우
			// itr가 리스트의 끝이 아닌 경우에 오른쪽으로 이동
			else if (c == '>') {
				if (itr != str.end()) ++itr;
			}

			// c가 백스페이스인 경우
			// itr가 리스트의 시작점이 아닌 경우, 현재 itr가 가리키는 문자의 바로 앞 문자 삭제
			else if (c == '-') {
				if (itr != str.begin()) {
					auto temp = itr;
					--temp;
					itr = str.erase(temp);
				}
			}

			// c가 일반 문자들인 경우
			// 문자를 하나씩 삽입
			else {
				str.insert(itr, c);
			}
		}
		
		BP
		for (auto c : str) std::cout << c;
		std::cout << '\n';
	}

	return 0;
}