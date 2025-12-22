#include <iostream>
#include <vector>
#include <algorithm>

// 1차 서류심사와 2차 면접시험 각각의 순위로 신규 사원을 채용하고자 함
// 단, 다른 모든 지원자와 비교했을 때 서류심사 성적과 면접시험 성적 중 적어도 하나가 다른 지원자보다 떨어지지 않는 사람만 채용함
// 이 때, 위 조건을 만족하면서 선발할 수 있는 최대 사원 수를 구하는 문제

int main() {
	int T;	std::cin >> T;

	while (T--) {
		int	N;	std::cin >> N;
		int answer = 1;

		// (서류 점수, 면접 점수) 순서쌍으로 저장
		// 이후 서류 점수를 기준으로 정렬 진행
		std::vector<std::pair<int, int>> vec(N);
		for (int i = 0; i < N; ++i) {
			std::cin >> vec[i].first >> vec[i].second;
		}
		std::sort(vec.begin(), vec.end());
	
		// 면접 순위 비교
		// 서류 점수가 가장 높은 사람의 면접 점수를 기준으로 비교 진행(서류 1위는 무조건 뽑힘)
		// 이전 사람보다 면접 순위가 낮으면 탈락(서류 점수 순으로 이미 정렬되었기 때문)
		int top = vec[0].second;
		for (int i = 1; i < N; ++i) {
			if (vec[i].second < top) {
				answer++;
				top = vec[i].second;
			}
		}
		std::cout << answer << '\n';
	}

	return 0;
}