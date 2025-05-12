#include <iostream>
#include <vector>

// 주어진 수열의 부분합 M이 가능한 경우의 수를 구하는 문제

using namespace std;

int main() {
	int N, M;
	int cnt = 0;
	cin >> N >> M;

	vector<int> vec(N);
	for (int i = 0; i < vec.size(); i++) {
		cin >> vec[i];
	}

	int start = 0;

	// 시작 위치를 0부터 N-1까지 차례대로 옮기며 검사
	while (start < vec.size()) {
		int sum = 0;

		for (int i = start; i < vec.size(); i++) {
			sum += vec[i];

			// 합이 M과 같으면 cnt 증가
			if (sum == M) {
				cnt++;
				break;
			}
		}
		start++;
	}

	cout << cnt;

	return 0;
}