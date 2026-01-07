#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/2621

int main() {
	int answer = 0;

	// 카드의 색과 숫자들을 두 개의 벡터로 분리
	// 카드에 적힌 숫자의 등장횟수를 저장하기 위한 map 선언
	std::vector<char> colors;
	std::vector<int> nums;
	std::map<int, int> cnt;

	for (int i = 0; i < 5; ++i) {
		char c; int n;
		std::cin >> c >> n;
		
		colors.push_back(c);
		nums.push_back(n);
		cnt[n]++;
	}

	// 스트레이트 확인을 위해 숫자는 모두 정렬
	std::sort(nums.begin(), nums.end());

	// 카드의 색깔이 모두 동일한지 확인
	bool isSameColor = true;
	for (int i = 1; i < 5; i++)
		if (colors[i] != colors[0])
			isSameColor = false;

	// 스트레이트 확인
	bool isStraight = true;
	for (int i = 0; i < 4; i++)
		if (nums[i] + 1 != nums[i + 1])
			isStraight = false;

	// 같은 숫자들이 나오는 경우(포카드와 트리플만 취급함)
	// 2페어는 두 개의 숫자들의 조합으로 가능하기 때문에 크기 2의 벡터로 만들어짐 
	int four = 0, three = 0;
	std::vector<int> pairs;

	// 등장횟수들을 만족하는 숫자 저장
	for (int i = 1; i <= 9; ++i) {
		if (cnt[i] == 4) four = i;
		else if (cnt[i] == 3) three = i;
		else if (cnt[i] == 2) pairs.push_back(i);
	}

	int max_num = nums.back();

	// 점수를 정하는 규칙에 맞게 점수 계산
	if (isSameColor && isStraight)
		answer = max_num + 900;
	else if (four != 0)
		answer = four + 800;
	else if(three != 0 && pairs.size() == 1)
		answer = three * 10 + pairs[0] + 700;
	else if(isSameColor)
		answer = max_num + 600;
	else if(isStraight)
		answer = max_num + 500;
	else if (three != 0)
		answer = three + 400;
	else if (pairs.size() == 2)
		answer = std::max(pairs[0], pairs[1]) * 10 + std::min(pairs[0], pairs[1]) + 300;
	else if (pairs.size() == 1)
		answer = pairs[0] + 200;
	else
		answer = max_num + 100;

	std::cout << answer;
	return 0;
}