#include <iostream>
#include <vector>
#include <climits>

// 여러 개의 파일(장)을 두 개씩 합쳐 최종적으로 하나의 파일을 만들고자 함
// 두 파일을 합칠 때 비용은 두 파일 크기의 합이며, 어떤 순서로 합치느냐에 따라 전체 비용이 달라질 수 있음
// 이 때, 파일들을 하나의 파일로 합칠 때 필요한 최소비용을 구하는 문제

const int MAX = 501;

int main() {
	int T;
	std::cin >> T;

	while (T--) {
		int K; 
		std::cin >> K;
	
		std::vector<int> vec(K + 1);
		std::vector<int> sum(K + 1, 0);

		// 2차원 vector : 구간 [s, e]까지를 합치는 데 드는 비용
		// 각 파일 하나씩을 합치는 데 드는 비용은 0
		std::vector<std::vector<int>> DP(K + 1, std::vector<int>(K + 1, 0)); 
		
		// 누적 합 계산
		for (int i = 1; i <= K; ++i) {
			std::cin >> vec[i];
			sum[i] = sum[i - 1] + vec[i];
		}

		// gap은 구해야하는 범위를 의미함 
		// s는 시작 인덱스로, s+gap이 K를 넘지 않도록 함. 즉 [s, s + 1], [s, s + 2], ... 순서가 됨 
		for (int gap = 1; gap < K; ++gap) {
			for (int s = 1; s + gap <= K; ++s) {
				int e = s + gap;
				DP[s][e] = INT_MAX;

				// 구간 [s,e]에 대해, s부터 e까지의 파일을 합치는 경우는 [s, m] + [m + 1, e]임 
				// 합친 뒤 [s, e] 구간에 대해 그만큼의 추가 비용이 발생함
				for (int m = s; m < e; ++m) {
					DP[s][e] = std::min(DP[s][e], DP[s][m] + DP[m + 1][e] + sum[e] - sum[s - 1]);
				}
			}
		}

		// 처음부터 끝까지 파일을 합치는데 드는 최소 비용을 출력
		std::cout << DP[1][K] << '\n';
	}

	return 0;
}