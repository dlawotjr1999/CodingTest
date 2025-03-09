#include <iostream>
#include <vector>
#include <set>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int N, M;
    std::cin >> N >> M;

    std::vector<std::vector<bool>> vec(N, std::vector<bool>(20, false));

    int prompt[3];

    for (int i = 0; i < M; i++) {
        std::cin >> prompt[0] >> prompt[1];
        int train = prompt[1] - 1;

        if (prompt[0] == 1 || prompt[0] == 2)
            std::cin >> prompt[2];

        switch (prompt[0]) {
        case 1:
            vec[train][prompt[2] - 1] = true;
            break;

        case 2:
            vec[train][prompt[2] - 1] = false;
            break;

        case 3:
            for (int j = 19; j > 0; j--)
                vec[train][j] = vec[train][j - 1];
            vec[train][0] = false;
            break;

        case 4:
            for (int j = 0; j < 19; j++)
                vec[train][j] = vec[train][j + 1];
            vec[train][19] = false;
        }
    }

    std::set<std::vector<bool>> trains(vec.begin(), vec.end());
    std::cout << trains.size();

    return 0;
}
