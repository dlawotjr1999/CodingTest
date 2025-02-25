#include <iostream>
#include <string>
#include <algorithm>

// ����
// ���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, �� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. ��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

// ���
// ù° �ٿ� �� �ܾ�� ���� ���� ���� ���ĺ��� �빮�ڷ� ����Ѵ�.��, ���� ���� ���� ���ĺ��� ���� �� �����ϴ� ��쿡�� ? �� ����Ѵ�.

int main() {
	int cnt[26] = {0,};
	int count;
	std::string s;
	std::string::iterator itr;

	std::cin >> s;
	for (itr = s.begin(); itr != s.end(); itr++) {
		if (*itr >= 97) *itr -= 32; //if (*itr >= 'a') *itr -= 32;
		int j = *itr - 65;
		(cnt[j])++;
	}
	//Uppercase

	int target = *std::max_element(cnt, cnt + 26);
	// ���� ���ĺ��� ������ ����� cnt �迭���� max ���� ã�Ƴ���.

	for (int i = 0; i < sizeof(cnt) / sizeof(int); i++) {
		count = std::count(std::begin(cnt), std::end(cnt), target);
	}
	// cnt �迭���� target��ŭ��(���� ū ��) ���� ã�Ƴ���.

	auto max_index = std::find(std::begin(cnt), std::end(cnt), target);

	if (count > 1) {
		std::cout << '?';
	}
	// �ߺ��� ���ĺ��� ���� �� ? ���

	else {
		int index = std::distance(cnt, max_index);
		index += 65;
		std::cout << (char)index;
	}
	// �׷��� ���� �� ���� ���� ���� ���ĺ� ���

	return 0;
}