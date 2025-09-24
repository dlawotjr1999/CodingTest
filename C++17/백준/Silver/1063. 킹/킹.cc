#include <iostream>
#include <map>
#include <string>


int main() {
    std::string king_pos, stone_pos;
    int N;
    std::cin >> king_pos >> stone_pos >> N;

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

        if (nkx == stone.first && nky == stone.second) {
            int nsx = stone.first + dx, nsy = stone.second + dy;
            
            if (nsx < 0 || nsx >= 8 || nsy < 0 || nsy >= 8) 
                continue;
            stone = { nsx, nsy };
        }

        king = { nkx, nky };
    }

    auto toPos = [](std::pair<int, int> p) {
        std::string res;
        res += char('A' + p.first);
        res += char('1' + p.second);
        return res;
    };

    std::cout << toPos(king) << "\n" << toPos(stone) << "\n";
    return 0;
}