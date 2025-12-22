#include <iostream>
#include <vector>

// 절단기에 높이 H를 지정하여 벌목을 하고자 함
// 높이가 H 이상인 나무는 H 위의 부분이 잘릴 것이고, 낮은 나무는 잘리지 않음
// H 위의 부분만큼의 나무들만큼을 가져갈 수 있음 
// 이 때, 적어도 M만큼의 나무를 가져가기 위해 절단기에 설정할 수 있는 높이의 최댓값을 구하는 문제

int answer;

int main() {
	int N, M;
	std::cin >> N >> M;

	int l = 0,  r = 0;

	// 최소 길이를 0, 최대 길이를 가장 긴 나무의 길이로 가정함
	std::vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> vec[i];
		r = std::max(r, vec[i]);
	}

	// 이분 탐색 진행
	while (l <= r) {
		int mid = (l + r) / 2;

		// 현재 가정한 나무의 길이보다 긴 나무의 윗부분을 자름
		// 자른 부분만큼의 나무를 가져감
		long long len = 0;
		for (int elm : vec) {
			if (elm >= mid)
				len += (elm - mid);
		}

		// 가져가야 하는 최소 길이(M)보다 긴 경우, 잘라야 하는 길이를 더 길게하여 탐색(잘려진 부분의 길이를 줄이기 위함)
		// 그렇지 않은 경우, 잘라야 하는 길이를 더 짧게하여 탐색
		if (M <= len) {
			answer = mid;
			l = mid + 1;
		}
		else
			r = mid - 1;
	}

	std::cout << answer;
	return 0;
}