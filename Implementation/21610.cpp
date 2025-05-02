#include <iostream>
#include <vector>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/21610

int N, M;

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

int ddx[4] = { -1,1,-1,1 };
int ddy[4] = { -1,-1,1,1 };

std::vector<std::vector<int>> field;   
std::vector<std::vector<bool>> cloud;  
std::vector<std::pair<int, int>> command;  

// 순환 보정 : 좌표를 1~N 범위로 순환 보정
int Revise(int x) {
    if (x > N) x = x % N;
    if (x < 1) x = N + (x % N);
    return x;
}

// 구름 이동 : dir에 따라 dist만큼 이동
void MoveCloud(int cnt) {
    int dir = command[cnt].first - 1; // 1-based to 0-based
    int dist = command[cnt].second;     
    std::vector<std::vector<bool>> temp_cloud(N + 1, std::vector<bool>(N + 1, false));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cloud[i][j]) {
                int nx = Revise(j + (dist * dx[dir]));
                int ny = Revise(i + (dist * dy[dir])); 

                temp_cloud[ny][nx] = true;
                field[ny][nx]++;  
            }
        }
    }
    cloud = temp_cloud;  
}

// 물 복사 마법 : 인접한 대각선 네 방향의 물이 있는 바구니의 수만큼 원래 위치의 바구니에 물이 증가
void WaterCopy() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (cloud[i][j]) {
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int nx = j + ddx[k], ny = i + ddy[k];
                    if (nx >= 1 && nx <= N && ny >= 1 && ny <= N && field[ny][nx] > 0) {
                        cnt++;
                    }
                }
                field[i][j] += cnt; 
            }
        }
    }
}

// 구름 생성 : 구름이 있었던 칸을 제외한 나머지 칸 중에서 물의 양이 2 이상인 칸에 구름이 생기며, 이 때 물의 양이 2만큼 줄어듦
void ReconstructCloud() {
    std::vector<std::vector<bool>> new_cloud(N + 1, std::vector<bool>(N + 1, false));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (!cloud[i][j] && field[i][j] >= 2) {
                new_cloud[i][j] = true;   
                field[i][j] -= 2;       
            }
        }
    }
    cloud = new_cloud;  
}

int main() {
    std::cin >> N >> M;

    field.resize(N + 1, std::vector<int>(N + 1, 0));
    cloud.resize(N + 1, std::vector<bool>(N + 1, false));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            std::cin >> field[i][j];
        }
    }

    // 비바라기 : (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름이 발생
    cloud[N][1] = true;
    cloud[N][2] = true;
    cloud[N - 1][1] = true;
    cloud[N - 1][2] = true;

    for (int i = 0; i < M; i++) {
        int d, s;
        std::cin >> d >> s;
        command.emplace_back(d, s);
    }

    for (int i = 0; i < M; i++) {
        MoveCloud(i);   
        WaterCopy();   
        ReconstructCloud();   
    }

    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            result += field[i][j];
        }
    }

    std::cout << result << '\n';

    return 0;
}
