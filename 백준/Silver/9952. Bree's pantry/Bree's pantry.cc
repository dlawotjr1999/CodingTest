#include <bits/stdc++.h>

int main() {
	while (true) {
		int n; std::cin >> n;
		
		if (n == 0)
			break;

		std::vector<std::pair<std::string, int>> vec(n);
		for (int i = 0; i < n; ++i) {
			std::cin >> vec[i].first >> vec[i].second;
		}
		std::sort(vec.begin(), vec.end(), [](auto& l, auto& r) {
			if (l.second == r.second) {
				std::string l_str = l.first;
				std::string r_str = r.first;
				
				std::transform(l_str.begin(), l_str.end(), l_str.begin(), ::toupper);
				std::transform(r_str.begin(), r_str.end(), r_str.begin(), ::toupper);

				return l_str < r_str;
			}

			return l.second > r.second;
		});

		std::deque<std::pair<std::string, int>> dq;
		dq.push_back(vec[0]);

		for (int i = 1; i < n; ++i) {
			if (i & 1) 
				dq.push_front(vec[i]);
			else 
				dq.push_back(vec[i]);
		}

		while (n--) {
			std::cout << dq.front().first << ' ';
			dq.pop_front();
		}
		std::cout << '\n';
	}
}