#include <iostream>
#include <string>

int answer;

int main() {
	int L, R;
	std::cin >> L >> R;

	std::string left = std::to_string(L);
	std::string right = std::to_string(R);
	size_t len = std::max(left.length(), right.length());

	if (left.length() < len) {
		left.insert(0, len - left.length(), '0');
	}
	if (right.length() < len) {
		right.insert(0, len - right.length(), '0');
	}

	for (int i = 0; i < len; ++i) {
		if (left[i] != right[i]) {
			break;
		}
		if (left[i] == '8' && right[i] == '8')
			answer++;
	}

	std::cout << answer;
	return 0;
}