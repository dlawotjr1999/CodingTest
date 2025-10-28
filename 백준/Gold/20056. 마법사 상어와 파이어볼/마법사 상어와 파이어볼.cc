#include <iostream>
#include <vector>

int dir_x[8] = { -1,-1,0,1,1,1,0,-1 };
int dir_y[8] = { 0,1,1,1,0,-1,-1,-1 };

int answer = 0;

struct info {
    int r, c, m, s, d;

    info(int r_, int c_, int m_, int s_, int d_)
        : r(r_), c(c_), m(m_), s(s_), d(d_) {
    }
};

int main() {
    int N, M, K;
    std::cin >> N >> M >> K;

    std::vector<info> info_vec;
    info_vec.reserve(M);

    for (int i = 0; i < M; ++i) {
        int r, c, m, s, d;
        std::cin >> r >> c >> m >> s >> d;
        info_vec.emplace_back(r, c, m, s, d);
    }

    while (K--) {
        std::vector<std::vector<std::vector<info>>> grid(N + 1, std::vector<std::vector<info>>(N + 1));

        for (auto& cur : info_vec) {
            int nr = (cur.r + dir_x[cur.d] * (cur.s % N) + N * 1000) % N;
            int nc = (cur.c + dir_y[cur.d] * (cur.s % N) + N * 1000) % N;

            if (nr == 0) nr = N;
            if (nc == 0) nc = N;

            grid[nr][nc].emplace_back(nr, nc, cur.m, cur.s, cur.d);
        }

        std::vector<info> new_vec;
        for (int r = 1; r <= N; ++r) {
            for (int c = 1; c <= N; ++c) {
                if (grid[r][c].empty())
                    continue;

                if (grid[r][c].size() == 1) {
                    new_vec.push_back(grid[r][c][0]);
                    continue;
                }

                int sum_m = 0, sum_s = 0;
                bool even = true, odd = true;

                for (auto& f : grid[r][c]) {
                    sum_m += f.m;
                    sum_s += f.s;
                    if (f.d % 2 == 0) odd = false;
                    else even = false;
                }

                int new_m = sum_m / 5;
                if (new_m == 0) 
                    continue;

                int new_s = sum_s / grid[r][c].size();
                std::vector<int> dirs = (even || odd) ? std::vector<int>{0, 2, 4, 6} : std::vector<int>{ 1, 3, 5, 7 };

                for (int d : dirs) {
                    new_vec.push_back({ r, c, new_m, new_s, d });
                }
            }
        }
        info_vec = std::move(new_vec);
    }

    for (auto& cur : info_vec)
        answer += cur.m;

    std::cout << answer;
    return 0;
}
