#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

// ���� ���� ����
// -10^9 �� X_i �� 10^9�̹Ƿ� long long �ڷ��� ���

int main() {
	int N;
	std::cin >> N;

	std::vector<long long> vec;	
	std::map<long long, long long> map;

	for (int i = 0; i < N; i++) {
		int elm;
		std::cin >> elm;

		vec.push_back(elm);
		map.insert({ vec[i], 0 }); // map�� ����Ǳ� ������ key�� ���� �ڵ����� ������ �̷����
	}

	// ���ĵ� key�� ���� value ����(��ǥ ������ ����), �� ���� ���� ���� 0���� �δ� ������ ����
	int i = 0;
	for (auto& elm : map) {
		elm.second = i++;
	}

	// ���� �Էµ� ������ ������ �°� ���(vec���� �Էµ� ������ �°� ���� ����Ǿ� �ֱ� ����)
	 /* NOTE : ector�� map�� ���ÿ� Ȱ���ϸ� ���� �Էµ� ������ �����ϸ鼭, Ư�� ���ؿ� ���� ��ȯ�� ���� ã�� �� ���� */
	for (auto& idx : vec) {
		std::cout << map[idx] << " ";
	}

	return 0;
}