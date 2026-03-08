#include <bits/stdc++.h>

int main() {
	int N, M, L, K;
	std::cin >> N >> M >> L >> K;

	std::vector<std::pair<int, int>> coords;
	for (int i = 0; i < K; ++i) {
		int x, y; std::cin >> x >> y;
		coords.emplace_back(x, y);
	}

    int max_val = 0;
    for (int i = 0; i < K; ++i) {
        int sx = coords[i].first;  

        for (int j = 0; j < K; ++j) {
            int sy = coords[j].second;  

            int cnt = 0;
            for (int k = 0; k < K; ++k) {
                int x = coords[k].first;
                int y = coords[k].second;

                if (sx <= x && x <= sx + L && sy <= y && y <= sy + L) {
                    cnt++;
                }
            }
            max_val= std::max(max_val, cnt);
        }
    }

    std::cout << (K - max_val);
    return 0;
}