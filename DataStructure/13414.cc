#include <bits/stdc++.h>

// 수강 신청에 부하 관리 시스템이 아래와 같이 동작할 때, 수강신청에 성공한 인원들을 구하는 문제
// - 수강신청 버튼이 활성화되면, 수강신청 버튼을 조금이라도 빨리 누른 학생이 대기목록에 먼저 들어감
// - 이미 대기열에 들어가 있는 상태에서 다시 수강신청 버튼을 누를 경우 대기목록의 맨 뒤로 밀려남
// - 잠시 후 수강신청 버튼이 비활성화 되면 대기목록에서 가장 앞에 있는 학생부터 자동으로 수강신청이 완료되며, 수강 가능 인원이 꽉 찰 경우 나머지 대기목록은 무시하고 수강신청을 종료함

int main() {
	int K, L;
	std::cin >> K >> L;

	std::map<std::string, int> map;
	for (int i = 0; i < L; ++i) {
		std::string num;
		std::cin >> num;

		// 중복된 대기목록은 갱신되어야 하기 때문에 value로 i를 사용함(value가 덮어씌워지기 때문)
		map[num] = i;
	}

	std::vector<std::pair<std::string, int>> students(map.begin(), map.end());

	// 순번대로 정렬 수행
	std::sort(students.begin(), students.end(), [&](const auto& l, const auto& r) {
		return l.second < r.second;
	});

	// 수강 신청 인원들이 수강 정원보다 작을 수 있으므로 그 중 최솟값을 택해야 함 
	for (int i = 0; i < std::min(K, (int)students.size()); ++i) {
		std::cout << students[i].first << '\n';
	}

	return 0;
}