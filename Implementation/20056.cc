#include <iostream>
#include <vector>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/20056

int dir_x[8] = { 0,1,1,1,0,-1,-1,-1 }; 
int dir_y[8] = { -1,-1,0,1,1,1,0,-1 };

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
        // 이동한 파이어볼들의 정보들을 저장하기 위한 임시 필드
        std::vector<std::vector<std::vector<info>>> grid(N + 1, std::vector<std::vector<info>>(N + 1));

        // 모든 파이어볼 이동
        for (auto& cur : info_vec) {
            int nr = (cur.r + dir_y[cur.d] * (cur.s % N) + N * 1000) % N;
            int nc = (cur.c + dir_x[cur.d] * (cur.s % N) + N * 1000) % N;

            // 1-based 보정   
            if (nr == 0) nr = N;
            if (nc == 0) nc = N;

            // 이동 후 grid에 저장
            // (nc, nr) 좌표에 존재할 수 있는 파이어볼들이 저장됨 
            grid[nr][nc].emplace_back(nr, nc, cur.m, cur.s, cur.d);
        }

        // 변화된 파이어볼들의 정보를 저장하는 벡터
        std::vector<info> new_vec;
        for (int r = 1; r <= N; ++r) {
            for (int c = 1; c <= N; ++c) {
                // 해당 좌표에 파이어볼이 없는 경우
                if (grid[r][c].empty())
                    continue;

                // 파이어볼이 하나인 경우 변화없이 그대로 저장
                if (grid[r][c].size() == 1) {
                    new_vec.push_back(grid[r][c][0]);
                    continue;
                }

                // 이하 두 개 이상의 파이어볼들이 존재하는 경우
                int sum_m = 0, sum_s = 0;
                bool even = true, odd = true;

                // 3-1, 3-2, 3-3을 위해 계산
                // 같은 칸 내의 파이어볼은 모두 합쳐짐
                for (auto& f : grid[r][c]) {
                    sum_m += f.m;
                    sum_s += f.s;
                    if (f.d % 2 == 0) odd = false;
                    else even = false;
                }

                // 새 질량은 floor((합쳐진 파이어볼 질량의 합)/5)
                // 질량이 0인 경우에는 소멸
                int new_m = sum_m / 5;
                if (new_m == 0) 
                    continue;

                // 새 속력은 floor((합쳐진 파이어볼 속력의 합)/(합쳐진 파이어볼의 개수))
                // 합쳐지는 파이어볼의 방향이 모두 홀수이거나 짝수이면 방향은 0, 2, 4, 6이 되고, 그렇지 않으면 1, 3, 5, 7
                int new_s = sum_s / grid[r][c].size();
                std::vector<int> dirs = (even || odd) ? std::vector<int>{0, 2, 4, 6} : std::vector<int>{ 1, 3, 5, 7 };

                // 4개의 새 파이어볼 생성
                for (int d : dirs) {
                    new_vec.push_back({ r, c, new_m, new_s, d });
                }
            }
        }

        // 다음 턴으로 갱신
        info_vec = std::move(new_vec);
    }

    // 최종 질량 합 계산
    for (auto& cur : info_vec)
        answer += cur.m;

    std::cout << answer;
    return 0;
}
