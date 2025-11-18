#include <iostream>
#include <vector>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/21608

// 각 학생과 4명의 좋아하는 학생들을 저장
struct info {
    int p;
    int friends[4];
};

int dir_x[4] = { -1,0,1,0 };
int dir_y[4] = { 0,-1,0,1 };

info board[21][21];
int answer;

int main() {
    int N; std::cin >> N;
    std::vector<info> vec(N * N + 1);

    for (int i = 1; i <= N * N; ++i) {
        info temp;	std::cin >> temp.p;

        for (int j = 0; j < 4; ++j) {
            int f; std::cin >> f;
            temp.friends[j] = f;
        }
        vec[i] = temp;
    }

    // 학생들의 정보를 순차적으로 확인하여 최적의 자리 탐색
    for (int seq = 1; seq <= N * N; ++seq) {
        info cur = vec[seq];

        int friend_cnt = -1;
        int empty_cnt = -1;
        int best_x = 0, best_y = 0;

        // 각 학생들에 대해, 존재하는 모든 자리들을 탐색하며 최적의 자리를 선정
        // 각 자리들마다의 계산을 통해 좋아하는 친구들의 수, 빈 자리들의 수의 최댓값과 가장 작은 행, 열의 번호를 갱신해나감
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {

                if (board[i][j].p != 0)
                    continue; 

                int cur_friend = 0, cur_empty = 0;

                for (int k = 0; k < 4; ++k) {
                    int dy = i + dir_y[k];
                    int dx = j + dir_x[k];

                    if (dx < 1 || dx > N || dy < 1 || dy > N)
                        continue;

                    if (board[dy][dx].p == 0)
                        cur_empty++;
                    else {
                        for (int w = 0; w < 4; ++w) {
                            if (board[dy][dx].p == cur.friends[w])
                                cur_friend++;
                        }
                    }
                }

                // 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정함
                // 위 조건을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 함
                // 위 조건을 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정함
                if (cur_friend > friend_cnt ||
                    (cur_friend == friend_cnt && cur_empty > empty_cnt) ||
                    (cur_friend == friend_cnt && cur_empty == empty_cnt && i < best_y) ||
                    (cur_friend == friend_cnt && cur_empty == empty_cnt && i == best_y && j < best_x)) {

                    friend_cnt = cur_friend;
                    empty_cnt = cur_empty;
                    best_x = j;
                    best_y = i;
                }
            }
        }

        // 모든 자리를 고려했을 때, 최적의 자리를 선정
        board[best_y][best_x] = cur;
    }

    // 주변의 좋아하는 학생들의 수에 따른 만족도 계산
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            info cur = board[i][j];
            int cnt = 0;

            // 한 자리에 대하여, 주변에 있는 좋아하는 사람 확인 후 그 인원수 계산
            for (int k = 0; k < 4; ++k) {
                int dy = i + dir_y[k];
                int dx = j + dir_x[k];

                if (dx < 1 || dx > N || dy < 1 || dy > N)
                    continue;

                for (int w = 0; w < 4; ++w) {
                    if (board[dy][dx].p == cur.friends[w])
                        cnt++;
                }
            }

            if (cnt == 1) answer += 1;
            else if (cnt == 2) answer += 10;
            else if (cnt == 3) answer += 100;
            else if (cnt == 4) answer += 1000;
        }
    }

    std::cout << answer;
    return 0;
}