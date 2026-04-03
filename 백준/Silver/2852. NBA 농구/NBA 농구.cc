#include <bits/stdc++.h>

std::string formatTime(int t) {
	int m = t / 60;
	int s = t % 60;
	std::string mm = (m < 10 ? "0" : "") + std::to_string(m);
	std::string ss = (s < 10 ? "0" : "") + std::to_string(s);
	return mm + ":" + ss;
}

int main() {
	int N;	std::cin >> N;

	std::vector<std::pair<int, int>> vec;
	while (N--) {
		int team;  std::string info;
		std::cin >> team >> info;

		std::string token = "";
		std::stringstream ss(info);

		int seconds = 0, t = 60;
		while (getline(ss, token, ':')) {
			int cur = std::stoi(token) * t;
			seconds += cur;
			t /= 60;
		}
		
		vec.emplace_back(team, seconds);
	}

	int score1 = 0, score2 = 0;
	int one_second = 0, two_second = 0;
	int prev = 0;

	for (int i = 0; i < vec.size(); ++i) {
		int team = vec[i].first;
		int cur = vec[i].second;
		int diff = cur - prev;

		if (score1 > score2) 
			one_second += diff;
		else if (score1 < score2) 
			two_second += diff;

		if (team == 1)
			score1++;
		else
			score2++;

		prev = cur;
	}
	
	int end = 48 * 60;
	int diff = end - prev;

	if (score1 > score2) one_second += diff;
	else if (score2 > score1) two_second += diff;

	std::cout << formatTime(one_second) << '\n';
	std::cout << formatTime(two_second) << '\n';
	return 0;
}