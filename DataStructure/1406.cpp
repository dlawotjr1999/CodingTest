#include <iostream>
#include <list>

// 아래 커맨드들을 지원하는 에디터를 구현하는 문제
// L : 커서를 왼쪽으로 한 칸 옮김 (커서가 문장의 맨 앞이면 무시됨)
// D : 커서를 오른쪽으로 한 칸 옮김 (커서가 문장의 맨 뒤이면 무시됨)
// B : 커서 왼쪽에 있는 문자를 삭제함 (커서가 문장의 맨 앞이면 무시됨)
// P $ : $라는 문자를 커서 왼쪽에 추가함

int main() {
	std::string input; 
	int N;

	std::cin >> input;
	std::cin >> N;

	// 문장들을 한 글자씩 이루어진 연결 리스트로 설정
	std::list<char> input_list(input.begin(), input.end());
	// 커서는 문장의 문장의 맨 뒤(리스트의 맨 뒤)에 위치
	auto cursor = input_list.end();

	for (int i = 0; i < N; ++i) {
		char cmd; std::cin >> cmd;
		
		if (cmd == 'L') {
			if (cursor == input_list.begin())
				continue;
			// 커서를 앞으로 한 칸 이동
			cursor--;
		}
		else if (cmd == 'D') {
			if (cursor == input_list.end())
				continue;
			// 커서를 뒤로 한 칸 이동
			cursor++;
		}
		else if (cmd == 'B') {
			// 커서가 처음 위치가 아닌 경우에만 현재 커서 앞의 문자를 지움
			if (cursor != input_list.begin())
				cursor = input_list.erase(--cursor);
		}
		// 현재 커서의 위치에 문자 하나를 삽입
		// 기존 커서의 위치에 있던 문자는 뒤로 밀려남
		else if (cmd == 'P') {
			char c;	std::cin >> c;
			input_list.insert(cursor, c);
		}
	}

	for (char c : input_list) std::cout << c;
	std::cout << "\n";

	return 0;
}