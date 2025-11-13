#include <iostream>
#include <vector>

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

    for (int seq = 1; seq <= N * N; ++seq) {
        info cur = vec[seq];

        int friend_cnt = -1;
        int empty_cnt = -1;
        int best_x = 0, best_y = 0;

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {

                if (board[i][j].p != 0)
                    continue; 

                int temp_friend = 0, temp_empty = 0;

                for (int k = 0; k < 4; ++k) {
                    int dy = i + dir_y[k];
                    int dx = j + dir_x[k];

                    if (dx < 1 || dx > N || dy < 1 || dy > N)
                        continue;

                    if (board[dy][dx].p == 0)
                        temp_empty++;
                    else {
                        for (int w = 0; w < 4; ++w) {
                            if (board[dy][dx].p == cur.friends[w])
                                temp_friend++;
                        }
                    }
                }

                if (temp_friend > friend_cnt ||
                    (temp_friend == friend_cnt && temp_empty > empty_cnt) ||
                    (temp_friend == friend_cnt && temp_empty == empty_cnt && i < best_y) ||
                    (temp_friend == friend_cnt && temp_empty == empty_cnt && i == best_y && j < best_x)) {

                    friend_cnt = temp_friend;
                    empty_cnt = temp_empty;
                    best_x = j;
                    best_y = i;
                }
            }
        }

        board[best_y][best_x] = cur;
    }

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            info cur = board[i][j];
            int cnt = 0;

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