#include <bits/stdc++.h>

// 지구에 떨어지는 별똥별의 수를 최소화하기 위해 L*L 크기의 트램펄린을 설치하고자 함
// 이 트램펄린으로 최대한 많은 별똥별을 다시 우주로 튕겨내고자 하며, 별똥별이 모서리에 부딪혀도 튕겨나가게 됨
// 트램펄린으로 최대한 많은 별똥별을 튕겨낼 때, 지구에 부딪히는 별똥별의 갯수를 구하는 문제

int main() {
	int N, M, L, K;
	std::cin >> N >> M >> L >> K;

	std::vector<std::pair<int, int>> coords;
	for (int i = 0; i < K; ++i) {
		int x, y; std::cin >> x >> y;
		coords.emplace_back(x, y);
	}

    // N과 M이 각각 최대 500,000까지 가능하므로 이를 활용하여 검사를 진행하기엔 비효율적임
    // 즉 별똥별이 떨어지는 K개의 좌표들을 이용하여 정답을 계산
    int max_val = 0;
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < K; ++j) {
            
            // 기준 좌표 설정
            // 트램펄린의 모서리에 별똥별이 부딪혀도 튕겨지기 때문에, 별똥별이 떨어지는 한 지점은 트램펄린의 모서리에 있어야 효율적임
            // 즉, 트램펄린을 설치해야하는 좌표는 별똥별의 좌표 (x, y)중 x나 y 하나는 포함해야 함
            // 이러한 이유로 기준 좌표들은 모든 k개들의 좌표(x, y)의 조합들로 이루어짐(총 K*K개의 경우의 수)
            int sx = coords[i].first;
            int sy = coords[j].second;  

            int cnt = 0;

            // 기준 좌표 설정 후 모든 지점에 대하여 검토 진행
            // 기준 좌표 (sx, sy)를 기준으로 트램펄린의 범위 안에 들어오는 구간은 [sx, sx + L]과 [sy, sy + L]
            for (int k = 0; k < K; ++k) {
                int x = coords[k].first;
                int y = coords[k].second;

                // 트램펄린의 범위 안에 들어오는 별들은 모두 튕겨낼 수 있음
                if (sx <= x && x <= sx + L && sy <= y && y <= sy + L) {
                    cnt++;
                }
            }

            // 각 경우마다 최대로 튕겨낼 수 있는 별똥별의 수 계산
            max_val= std::max(max_val, cnt);
        }
    }

    // (총 별똥별의 갯수 - 튕겨낸 별똥별의 갯수)가 정답
    std::cout << (K - max_val);
    return 0;
}