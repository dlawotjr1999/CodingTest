#include <bits/stdc++.h>
#include <unordered_set>

// 개강총회 참석 인원을 확인하여 그 인원수를 구하는 문제
// 출석부는 아래와 같은 규칙으로 관리됨
// 1. 개강총회 이전에 채팅 로그가 존재하면 체크. 시작하자마자 채팅 로그를 남겨도 제 시간 입장으로 간주함
// 2. 개강총회가 끝나고 스트리밍이 끝나면 채팅 로그를 통해 퇴장 확인 여부 확인. 스트리밍이 끝나자마자  채팅 로그를 남겨도 퇴장이 확인된 것으로 간주함

int answer;

// 시간은 HH:MM 형태로 입력이 되기 때문에 HH와 MM만 추려서 분 단위로 변환하여 반환
inline int time_to_int(const std::string& str) {
	int hour = std::stoi(str.substr(0, 2));
	int minute = std::stoi(str.substr(3, 2));

	return (hour * 60) + minute;
}

int main() {
	// 개강총회 시작시간, 종료시간, 스트리밍 종료시간 입력
	int time_arr[3];

	for (int i = 0; i < 3; ++i) {
		std::string input; // S, E, Q
		std::cin >> input;
		
		time_arr[i] = time_to_int(input);
	}

	// early 집합 : 개강총회가 열리기 이전에 집계된 채팅 로그를 저장
	// counted 집합 : 개강총회가 열리는 동안 집계된 채팅 로그를 저장
	std::unordered_set<std::string> early;
	std::unordered_set<std::string> counted;

	std::string time, name;
	while (std::cin >> time >> name) {
		int t = time_to_int(time);

		// 개강총회 시작 전 채팅 로그가 확인되면 early 집합에 추가
		if (t <= time_arr[0]) { 
			early.insert(name);
		}

		// 개강 총회가 진행되는 동안 채팅 로그가 확인 되는 경우
		// 시작 전 채팅 로그가 존재할 때, 총회가 진행되는 동안 그 로그가 존재하면 출석으로 인정함 
		else if (time_arr[1] <= t && t <= time_arr[2]) { 
			if (early.find(name) != early.end() && counted.insert(name).second) {
				answer++;
			}
		}
	}

	std::cout << answer;
	return 0;
}