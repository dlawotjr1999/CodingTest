#include <iostream>
#include <vector>
#include <algorithm>

// N개의 퀘스트가 있으며, 각 퀘스트는 일정 수치의 경험치 부여
// M개의 아케인 스톤을 사용하여 퀘스트를 완료할 수 있음
// 퀘스트를 완료할 때마다, 해당 퀘스트의 경험치 보상에 현재 활성화된 아케인 스톤에 경험치 축적
// 이 때 획득할 수 있는 최대 경험치를 구하는 문제
// idea : 경험치 보상이 낮은 순서대로 완료하면 최댓값을 구할 수 있음

std::vector<long long> stones;
long long xp;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);

	long long n, k;
	std::cin >> n >> k;

	stones.resize(n);
	for (long long& stone : stones) {
		std::cin >> stone;
	}

	// 경험치 순서대로 오름차순 정렬
	std::sort(stones.begin(), stones.end());

	/*
	예시로 n = 6, k = 3일때

	100; 200 + 300 + 400 + 500 + 600
	200; 300 + 400 + 500 + 600
	300; 400 + 500 + 600
	400;
	500;
	600;

	위와 같은 방식으로 축적을 시켜야 최댓값을 구할 수 있음
	즉 (1 * 200) + (2 * 300) + (3 * 400) + (3 * 500) + (3 * 600) = 5300이 최댓값이므로
	s(i) = min(i, k) * stones[i]를 유도할 수 있다 
	*/
	for (long long i = 1; i < stones.size(); i++) {
		long long temp = stones[i] * std::min(i, k);
		xp += temp;
	}

	std::cout << xp;

	return 0;
}