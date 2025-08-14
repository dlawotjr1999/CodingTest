#include <bits/stdc++.h>

// 각 옵션에 단축키를 의미하는 대표 알파벳을 지정하기로 했을 때, 단축키를 지정하는 법은 아래의 순서를 따름
// 1. 먼저 하나의 옵션에 대해 왼쪽에서부터 오른쪽 순서로 단어의 첫 글자가 이미 단축키로 지정되었는지 살펴보며, 만약 단축키로 아직 지정이 안 되어있다면 그 알파벳을 단축키로 지정함
// 2. 만약 모든 단어의 첫 글자가 이미 지정이 되어있다면 왼쪽에서부터 차례대로 알파벳을 보면서 단축키로 지정 안 된 것이 있다면 단축키로 지정함
// 3. 어떠한 것도 단축키로 지정할 수 없다면 그냥 놔두며 대소문자를 구분치 않음
// 4. 위의 규칙을 첫 번째 옵션부터 N번째 옵션까지 차례대로 적용함
// 단어들이 주어질 때, 위 규칙을 따라 단축키로 지정된 알파벳 좌우에 [] 괄호를 씌워서 표현한 후 출력하는 문제

// Note : 문자 자체에 신경을 쓰는 것보다, 그 문자가 위치한 인덱스를 활용하는 것이 더 효율적임

bool alphabet[26];

int main() {
	int N;
	std::cin >> N;

	std::vector<std::string> commands(N);

	// 공백 문자열을 입력받기 위해 std::cin.ignore() 사용
	std::cin.ignore();
	for (int i = 0; i < N; ++i) {
		std::getline(std::cin, commands[i]);
	}

	for (int i = 0; i < N; ++i) {
		std::string& command = commands[i];
		// 벡터에는 command의 각 단어의 시작 인덱스를 저장
		std::vector<int> idx_vec;

		// command가 공백 문자열이 아닌 경우에는 첫 단어의 인덱스인 0을 추가함
		if (!command.empty())
			idx_vec.push_back(0);
		for (int i = 0; i < command.size(); ++i) {
			// command의 사이즈를 넘지 않는 선에서 공백이 있는 위치를 찾아서 그 다음 인덱스를 추가함
			if (command[i] == ' ' && i + 1 < command.size())
				idx_vec.push_back(i + 1);
		}
		bool is_checked = false;

		// 먼저 각 단어의 첫 글자가 단축키로 지정되어 있는지 확인
		for (int idx : idx_vec) {
			// 대소문자를 구분하지 않기 위해 tolower 사용
			char lower_c = tolower(command[idx]);

			if (!alphabet[lower_c - 'a']) {
				command.insert(idx, "[");
				// '[' 삽입으로 인한 인덱스 변화로 인해 idx + 2 위치에 ']'를 삽입
				command.insert(idx + 2, "]");
				alphabet[lower_c - 'a'] = true;
				// 단축키가 지정되었음을 나타내는 플래그를 true로 설정
				is_checked = true;
				break;
			}
		}

		// 만약 단축키가 지정되지 않았다면, 왼쪽에서부터 차례대로 알파벳을 보면서 단축키로 지정되지 않은 문자를 찾아서 지정함
		if (!is_checked) {
			for (int j = 0; j < command.size(); ++j) {
				if (!isalpha(command[j]))
					continue;
				char lower_c = tolower(command[j]);

				if (!alphabet[lower_c - 'a']) {
					command.insert(j, "[");
					command.insert(j + 2, "]");
					alphabet[lower_c - 'a'] = true;
					break;
				}
			}
		}
	}

	for (const std::string& command : commands) {
		std::cout << command << '\n';
	}

	return 0;
}