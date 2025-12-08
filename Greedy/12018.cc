#include <iostream>
#include <vector>
#include <algorithm>

// 마일리지 수강신청 제도가 있을 때, 이 제도는 각각의 학생들에게 마일리지를 주어 듣고 싶은 과목에 마일리지를 과목당 1~36을 분배함 
// 그리고 모두 분배가 끝이 나면 과목에 대해서 마일리지를 많이 투자한 순으로 그 과목의 수강인원만큼 신청되는 방식을 사용함
// 다른 사람들이 신청한 마일리지들을 볼 수 있을 때, 주어진 마일리지로 수강할 수 있는 최대 강의의 수를 구하는 문제

int answer;

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> mileage;

	while (n--) {
		int p, l;
		std::cin >> p >> l;

		// 각 강의를 신청한 학생들의 마일리지 저장
		// 필요한 최소 마일리지를 구하기 위해 오름차순 정렬
		std::vector<int> subject(p);
		for (int i = 0; i < p; ++i) {
			std::cin >> subject[i];
		}
		std::sort(subject.begin(), subject.end());

		// 수강신청을 한 인원이 수강정원보다 적으면 1의 마일리지 투자로 수강 가능
		// 그렇지 않은 경우, 수강정원에 해당하는 사람(p-l번째 사람)의 마일리지만큼 마일리지를 투자하면 강의를 선점할 수 있음
		if(p < l)
			mileage.push_back(1);
		else
			mileage.push_back(subject[p - l]);
	}

	// 각 강의 당 필요한 마일리지를 차감해가며 수강 가능한 강의의 수를 구함
	std::sort(mileage.begin(), mileage.end());
	for (int mil : mileage) {
		m -= mil;
		if (m < 0)
			break;
		answer++;
	}

	std::cout << answer;
	return 0;
}