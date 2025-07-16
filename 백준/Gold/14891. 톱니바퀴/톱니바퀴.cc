#include <bits/stdc++.h>

int score;

void rotate(std::string& gear, int cmd) {
	if (cmd == 1) {  
		char temp = gear.back();
		gear.pop_back();
		gear.insert(gear.begin(), temp);
	}
	else {  
		char temp = gear.front();
		gear.erase(gear.begin());
		gear.push_back(temp);
	}
}

int main() {
	std::vector<std::string> gears(4);
	for (int i = 0; i < 4; ++i) {
		std::cin >> gears[i];
	}

	int K; 
	std::cin >> K;

	std::vector<std::pair<int, int>> commands(K);
	for (int i = 0; i < K; ++i) {
		int a, b;
		std::cin >> a >> b;
		commands[i] = { a, b };
	}

	for (auto& [num, cmd] : commands) {
		int dir[4] = { 0,0,0,0 };
		dir[num - 1] = cmd;

		for (int i = num - 1; i > 0; --i) {
			if (gears[i][6] != gears[i - 1][2])
				dir[i - 1] = -dir[i];  // 
			else
				break;              
		}

		for (int i = num - 1; i < 3; ++i) {
			if (gears[i][2] != gears[i + 1][6])
				dir[i + 1] = -dir[i];
			else
				break;
		}

		for (int i = 0; i < 4; ++i) {
			if (dir[i] != 0)
				rotate(gears[i], dir[i] == 1 ? 1 : 0);
		}
	}


	for (int i = 0; i < 4; ++i) {
		if (gears[i][0] == '1') {
			score += (1 << i);  
		}
	}

	std::cout << score;
	return 0;
}