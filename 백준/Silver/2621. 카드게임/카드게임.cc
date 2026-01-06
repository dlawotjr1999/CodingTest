#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main() {
	int answer = 0;

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
	std::sort(nums.begin(), nums.end());

	bool isSameColor = true;
	for (int i = 1; i < 5; i++)
		if (colors[i] != colors[0])
			isSameColor = false;

	bool isStraight = true;
	for (int i = 0; i < 4; i++)
		if (nums[i] + 1 != nums[i + 1])
			isStraight = false;

	int four = 0, three = 0;
	std::vector<int> pairs;

	for (int i = 1; i <= 9; ++i) {
		if (cnt[i] == 4) four = i;
		else if (cnt[i] == 3) three = i;
		else if (cnt[i] == 2) pairs.push_back(i);
	}

	int max_num = nums.back();

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