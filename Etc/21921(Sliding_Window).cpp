#include <iostream>
#include <vector>
#include <map>

std::vector<int> people;
std::map<int, int> map;

int main() {
	int N, X;
	std::cin >> N >> X;

	people.resize(N);

	for (int& person : people) {
		std::cin >> person;
	}

	int cur_sum = 0;
	for (int i = 0; i < X; i++) {
		cur_sum += people[i];
	}
	
	int max_sum = cur_sum;
	int cnt = 1;

	for (int i = X; i < N; i++) {
		cur_sum += (people[i] - people[i - X]);

		if (cur_sum > max_sum) {
			max_sum = cur_sum;
			cnt = 1;
		}
		else if (cur_sum == max_sum)
			cnt++;
	}

	if (max_sum == 0) 
		std::cout << "SAD";
	else
		std::cout << max_sum << '\n' << cnt;

	return 0;
}