#include <iostream>
#include <map>
#include <string>

// 아래 문제를 구현
// https://www.acmicpc.net/problem/1063

int main() {
    std::string king_pos, stone_pos;
    int N;
    std::cin >> king_pos >> stone_pos >> N;

    // 변환 없이 char을 사용해도 무방하나, 경계값 검사를 용이하게 하기 위해 int 형으로 변환
    std::pair<int, int> king = { king_pos[0] - 'A', king_pos[1] - '1' };
    std::pair<int, int> stone = { stone_pos[0] - 'A', stone_pos[1] - '1' };

    std::map<std::string, std::pair<int, int>> move = {
        {"R",  {1, 0}}, {"L",  {-1, 0}}, {"B",  {0,-1}}, {"T",  {0, 1}},
        {"RT", {1, 1}}, {"LT", {-1, 1}}, {"RB", {1,-1}}, {"LB", {-1,-1}}
    };

    for (int i = 0; i < N; i++) {
        std::string cmd; 
        std::cin >> cmd;
        int dx = move[cmd].first;
        int dy = move[cmd].second;

        int nkx = king.first + dx, nky = king.second + dy;

        if (nkx < 0 || nkx >= 8 || nky < 0 || nky >= 8) 
            continue;

        // 킹이 이동하고자 하는 위치에 돌이 있을 경우 같은 방향으로 돌을 이동
        if (nkx == stone.first && nky == stone.second) {
            int nsx = stone.first + dx, nsy = stone.second + dy;
            
            if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8) 
                continue;
            stone = { nsx, nsy };
        }

        // 킹을 한 칸 이동
        king = { nkx, nky };
    }

    // 갱신된 위치를 다시 문자열로 변환
    auto toPos = [](std::pair<int, int> p) {
        std::string res;
        res += char('A' + p.first);
        res += char('1' + p.second);
        return res;
    };

    std::cout << toPos(king) << "\n" << toPos(stone) << "\n";
    return 0;
}