#include <iostream>
#include <vector>

// 전위 순회를 후위 순회로 바꾸는 문제

std::vector<int> bin_tree;

void PostOrder(int begin, int end) {
	int left = begin + 1;
	int right = begin + 1;
	while (right <= end && bin_tree[right] <= bin_tree[begin])
		right++;

	if (left < right)
		PostOrder(left, right - 1);
	if (right <= end)
		PostOrder(right, end);
	std::cout << bin_tree[begin] << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0); 
	std::cout.tie(0);

	int num;
	while (std::cin >> num)
		bin_tree.emplace_back(num);

	PostOrder(0, bin_tree.size() - 1);

	return 0;
}