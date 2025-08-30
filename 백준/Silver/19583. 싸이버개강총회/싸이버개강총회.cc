#include <bits/stdc++.h>
#include <unordered_set>

int answer;

inline int time_to_int(const std::string& str) {
	int hour = std::stoi(str.substr(0, 2));
	int minute = std::stoi(str.substr(3, 2));

	return (hour * 60) + minute;
}

int main() {
	int time_arr[3];

	for (int i = 0; i < 3; ++i) {
		std::string input; // S, E, Q
		std::cin >> input;
		
		time_arr[i] = time_to_int(input);
	}

	std::unordered_set<std::string> early;
	std::unordered_set<std::string> counted;

	std::string time, name;
	while (std::cin >> time >> name) {
		int t = time_to_int(time);

		if (t <= time_arr[0]) { 
			early.insert(name);
		}
		else if (time_arr[1] <= t && t <= time_arr[2]) { 
			if (early.find(name) != early.end() && counted.insert(name).second) {
				++answer;
			}
		}
	}

	std::cout << answer;
	return 0;
}